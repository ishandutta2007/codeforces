#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long

const int N = 1e6 + 11;

int v[N*4],p[N*4],w[N*4],ans[N*4];
vector<int> vv[N];

void build(int i, int l, int r)
{
    v[i]=0;
    w[i]=0;
    p[i]=l;
    if (l==r) return;
    int mid=(l+r)/2;
    build(i+i,l,mid);
    build(i+i+1,mid+1,r);
}

void push(int i)
{
    v[i+i]+=w[i];
    v[i+i+1]+=w[i];
    w[i+i]+=w[i];
    w[i+i+1]+=w[i];
    w[i]=0;
}

void update(int i, int l, int r, int tl, int tr, int x)
{
    if (tl<=l&&r<=tr)
    {
        v[i]+=x;
        w[i]+=x;
        return;
    }
    if (tl>r||l>tr) return;
    int mid=(l+r)/2;
    push(i);
    update(i+i,l,mid,tl,tr,x);
    update(i+i+1,mid+1,r,tl,tr,x);
    if (v[i+i]<v[i+i+1])
    {
        v[i]=v[i+i];
        p[i]=p[i+i];
    } else
    {
        v[i]=v[i+i+1];
        p[i]=p[i+i+1];
    }
}

void up()
{
    int n;
    cin>>n;
    vector<int> l1,r1,pos;
    for (int i=1; i<=n; i++)
    {
        int c;
        cin>>c;
        vv[i].clear();
        if (c!=-1)
        {
            if (c!=i+1)
            {
                l1.pb(i+1);
                r1.pb(c-1);
                pos.pb(i);
            }
            if (c!=n+1)
            {
                l1.pb(i);
                r1.pb(i);
                pos.pb(c);
            }
        }
    }
    build(1,1,n);
    for (int j=0; j<pos.size(); j++)
    {
        update(1,1,n,l1[j],r1[j],1);
        vv[pos[j]].pb(j);
    }
    for (int j=1; j<=n; j++)
    {
        int t=p[1];
        if (v[1]!=0) {cout<<-1<<"\n"; return;}
        ans[t]=n-j+1;
        update(1,1,n,t,t,1e9);
        for (int j=0; j<vv[t].size(); j++)
            update(1,1,n,l1[vv[t][j]],r1[vv[t][j]],-1);
    }
    for (int i=1; i<=n; i++)
        cout<<ans[i]<<" ";
    cout<<"\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
        up();
}