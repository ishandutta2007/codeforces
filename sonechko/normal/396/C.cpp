#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 4e5 + 11;
const int MOD = 1e9 + 7;

int p[N],tin[N],tout[N],d[N],timm,deep[N];
vector<int> v[N];
int w1[N*4],w2[N*4];

void dfs(int l)
{
    timm++;
    tin[l]=timm;
    d[timm]=l;
    for (int j=0; j<v[l].size(); j++)
    {
        deep[v[l][j]]=deep[l]+1;
        dfs(v[l][j]);
    }
    tout[l]=timm;
}

void push(int i)
{
    w1[i*2]=(w1[i*2]+w1[i])%MOD;
    w1[i*2+1]=(w1[i*2+1]+w1[i])%MOD;
    w2[i*2]=(w2[i*2]+w2[i])%MOD;
    w2[i*2+1]=(w2[i*2+1]+w2[i])%MOD;
    w1[i]=0;
    w2[i]=0;
}

void update(int i, int l, int r, int tl, int tr, int x1, int x2)
{
    if (tl<=l&&r<=tr)
    {
        w1[i]=(w1[i]+x1)%MOD;
        w2[i]=(w2[i]+x2)%MOD;
        //cout<<i<<" - "<<w1[i]<<" "<<w2[i]<<endl;
        return;
    }
    if (tl>r||l>tr) return;
    int mid=(l+r)/2;
    push(i);
    update(i*2,l,mid,tl,tr,x1,x2);
    update(i*2+1,mid+1,r,tl,tr,x1,x2);
}

int get(int i, int l, int r, int x)
{
    if (l==r) return (w1[i]*1ll+w2[i]*1ll*deep[x])%MOD;
    int mid=(l+r)/2;
    push(i);
    if (tin[x]<=mid) return get(i*2,l,mid,x);
    return get(i*2+1,mid+1,r,x);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=2; i<=n; i++)
    {
        cin>>p[i];
        v[p[i]].pb(i);
    }
    dfs(1);
    int t;
    cin>>t;
    for (int i=1; i<=t; i++)
    {
        int type;
        cin>>type;
        if (type==1)
        {
            int l,x,k;
            cin>>l>>x>>k;
            //cout<<tin[l]<<".."<<tout[l]<<" + "<<(x+(k*1ll*deep[l])%MOD)%MOD<<endl;
            //cout<<" - "<<k<<endl;
            //cout<<endl;
            update(1,1,n,tin[l],tout[l],(x+(k*1ll*deep[l])%MOD)%MOD,MOD-k);
        } else
        {
            int l;
            cin>>l;
            //cout<<l<<" - "<<get(1,1,n,l)<<endl;
            cout<<get(1,1,n,l)<<"\n";
        }
    }
}
/**
1   2   3   4   5   6   7   8   9   10
0   0   0   0   71  111 111 83  83  0
0   0   0   0   -39  -98 -98 -66 -66 0
**/