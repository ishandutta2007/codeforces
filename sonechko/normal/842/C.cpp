#include<bits/stdc++.h>
using namespace std;
//#define endl "\n"
#define mp make_pair
#define ss second
#define ff first
#define ll long long
#define ld long double
#define pb push_back
const int MOD = 1e9 + 7;
#define mod %MOD


const int N = 2e5 + 11;
vector<int> dil,v[N];
int ans[N],a[N],use[N];
int gcd(int l, int r)
{
    if (l==0||r==0) return max(l,r);
    return __gcd(l,r);
}
void dfs(int l, int r, vector<int> c)
{
    use[l]=1;
    if (l!=1)
    {
        int k=a[l];
        r=gcd(r,a[l]);
        for (int i=0; i<c.size(); i++)
        if (k%dil[i]==0) {k/=dil[i];} else
        if (c[i]==-2) {} else
        if (c[i]==-1) c[i]=l; else
        c[i]=-2;
        vector<pair<int,int> > vv;
        int res=1;
        for (int i=0; i<c.size(); i++)
            if (c[i]>=0) vv.pb(mp(c[i],dil[i])); else
            if (c[i]==-1) res*=dil[i];
        sort(vv.begin(),vv.end());
        int kk=1;
        ans[l]=max(r,res);
        for (int i=0; i<vv.size(); i++)
            if (i==0||(vv[i].ff==vv[i-1].ff)) {kk*=vv[i].ss; ans[l]=max(ans[l],res*kk);}
            else {kk=vv[i].ss; ans[l]=max(ans[l],res*kk);}
    } else ans[l]=a[l];
    for (int i=0; i<v[l].size(); i++)
        if (use[v[l][i]]==0) dfs(v[l][i],r,c);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<n; i++)
    {
        int l,r;
        cin>>l>>r;
        v[l].pb(r);
        v[r].pb(l);
    }
    int k=a[1];
    int d=2;
    vector<int> c;
    while (d*d<=k)
    {
        while (k%d==0)
        {
            dil.pb(d);
            c.pb(-1);
            k/=d;
        }
        d++;
    }
    if (k!=1) {dil.pb(k); c.pb(-1);}
    dfs(1,0,c);
    for (int i=1; i<=n; i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}