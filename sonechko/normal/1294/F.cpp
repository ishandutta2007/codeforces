#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define ff first
#define ss second
#define mp make_pair

const int N = 3e5 + 11;

int dp1[N],dp2[N];
int c1[N],c2[N],c3[N];
vector<int> v[N];
int aa,bb,cc,ans;

void dfs(int l, int pr)
{
    for (int j=0; j<v[l].size(); j++)
        if (v[l][j]!=pr) dfs(v[l][j],l);
    dp1[l]=0;
    c1[l]=l;
    for (int j=0; j<v[l].size(); j++)
        if (v[l][j]!=pr&&dp1[v[l][j]]+1>dp1[l])
        {
            dp1[l]=dp1[v[l][j]]+1;
            c1[l]=c1[v[l][j]];
        }
    dp2[l]=0;
    c2[l]=l;
    c3[l]=l;
    for (int j=0; j<v[l].size(); j++)
        if (v[l][j]!=pr&&dp2[v[l][j]]+1>dp2[l])
        {
            dp2[l]=dp2[v[l][j]]+1;
            c2[l]=c2[v[l][j]];
            c3[l]=c3[v[l][j]];
        }
    pair<int,int> p1=mp(-1,0),p2=mp(-1,0);
    for (int j=0; j<v[l].size(); j++)
        if (v[l][j]!=pr)
    {
        int to=v[l][j];
        if (dp1[to]>p1.ff) {p2=p1; p1=mp(dp1[to],c1[to]);} else
        if (dp1[to]>p2.ff) {p2=mp(dp1[to],c1[to]);}
    }
    if (p1.ff+p2.ff+2>dp2[l]&&p2.ss!=0)
    {
        dp2[l]=p1.ff+p2.ff+2;
        c2[l]=p1.ss;
        c3[l]=p2.ss;
    }
    p1=mp(-1,0);
    p2=mp(-1,0);
    pair<int,int> p3=mp(-1,0);
    for (int j=0; j<v[l].size(); j++)
        if (v[l][j]!=pr)
    {
        int to=v[l][j];
        if (dp1[to]>p1.ff) {p3=p2; p2=p1; p1=mp(dp1[to],c1[to]);} else
        if (dp1[to]>p2.ff) {p3=p2; p2=mp(dp1[to],c1[to]);} else
        if (dp1[to]>p3.ff) {p3=mp(dp1[to],c1[to]);}
    }
    if (p1.ff+p2.ff+p3.ff+3>ans&&p3.ss!=0)
    {
        ans=p1.ff+p2.ff+p3.ff+3;
        aa=p1.ss;
        bb=p2.ss;
        cc=p3.ss;
    }
    if (p1.ff+p2.ff+2>ans&&p2.ss!=0)
    {
        ans=p1.ff+p2.ff+p3.ff+2;
        aa=p1.ss;
        bb=p2.ss;
        cc=l;
    }
    for (int j=0; j<v[l].size(); j++)
        if (v[l][j]!=pr)
    {
        int to=v[l][j];
        int res=dp2[to];
        int aaa=c2[to],bbb=c3[to],ccc;
        if (p1.ss!=c1[to]) {res+=p1.ff; ccc=p1.ss;} else
        if (p2.ss==0)  res=-2e9; else {res+=p2.ff; ccc=p2.ss;}
        if (res+2>ans)
        {
            ans=res+2;
            aa=aaa;
            bb=bbb;
            cc=ccc;
        }
        if (dp2[to]+1>ans)
        {
            ans=dp2[to]+1;
            aa=aaa;
            bb=bbb;
            cc=l;
        }
    }
    ///cout<<l<<": "<<dp2[l]<<" "<<c2[l]<<":"<<c3[l]<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<n; i++)
    {
        int l,r;
        cin>>l>>r;
        v[l].pb(r);
        v[r].pb(l);
    }
    ans=0;
    dfs(1,0);
    cout<<ans<<"\n";
    if (aa==bb&&aa==cc)
    {
        if (aa==1) {bb=2; cc=3;} else
        if (aa==2) {bb=1; cc=1;}
    } else
    if (aa==bb)
    {
        if (aa!=1&&cc!=1) bb=1; else
        if (aa!=2&&cc!=2) bb=2; else bb=3;
    }
    if (aa==cc)
    {
        if (aa!=1&&bb!=1) cc=1; else
        if (aa!=2&&bb!=2) cc=2; else cc=3;
    }
    if (bb==cc)
    {
        if (aa!=1&&bb!=1) cc=1; else
        if (aa!=2&&bb!=2) cc=2; else cc=3;
    }
    cout<<aa<<" "<<bb<<" "<<cc<<"\n";
}