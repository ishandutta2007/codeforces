#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back
const int N = 1e6 + 11;
#define int ll

vector<int> v[N];
int pp[N],pd[N],pred[N],ss[N];
int use[N],n;
void dd(int l, int r)
{
    int xx=n+2;
    int yy=0;
    while (1==1)
    {
        xx=min(xx,l);
        yy=max(yy,l);
        if (l==r) break;
        use[l]=2;
        l=pred[l];
    }
    pp[xx]=yy-1;
}
void dfs(int l, int pr)
{
    use[l]=1;
    pred[l]=pr;
    for (int i=0; i<v[l].size(); i++)
        if (use[v[l][i]]==0) dfs(v[l][i],l); else
        if (use[v[l][i]]==1&&v[l][i]!=pr)
        {
            dd(l,v[l][i]);
        }
    use[l]=2;
}
int sum(int l, int r)
{
    int ps=r*(r+1)/2;
    ps-=l*(l-1)/2;
    return ps;
}
main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int m;
    cin>>n>>m;
    for (int i=1; i<=m; i++)
    {
        int l,r;
        cin>>l>>r;
        v[l].pb(r);
        v[r].pb(l);
    }
    for (int i=1; i<=n; i++)
        pp[i]=n;
    for (int i=1; i<=n; i++)
        if (use[i]==0) dfs(i,0);
    for (int i=n-1; i>=1; i--)
        pp[i]=min(pp[i],pp[i+1]);
    for (int i=1; i<=n; i++)
        pd[i]=pp[i]-i+1;
    for (int i=1; i<=n; i++)
        ss[i]=ss[i-1]+pd[i];
    int ks;
    cin>>ks;
    for (int i=1; i<=ks; i++)
    {
        int l1,r1;
        cin>>l1>>r1;
        int l=l1,r=r1;
        while(r-l>1)
        {
            int mid=(l+r)/2;
            if (pp[mid]<r1) l=mid; else r=mid;
        }
        if (pp[r]<r1)
        {cout<<ss[r]-ss[l1-1]+(r1-r)*(r1+1)-(sum(r+1,r1))<<"\n";}
        else
        if (pp[l]<r1)
        {cout<<ss[l]-ss[l1-1]+(r1-l)*(r1+1)-sum(l+1,r1)<<"\n";}
        else
        cout<<(r1-l1+1)*(r1+1)-sum(l1,r1)<<"\n";
    }
}