#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define ff first
#define ss second
#define pb push_back

const int N = 2e5 + 11;
const int MOD = 998244353;

int dp[N],a[N];
vector<pair<int,pair<int,int> > > v[N];

bool can(int l, int r)
{
    int mn=2e9;
    int res=1;
    for (int i=l; i<=r; i++)
        {
            v[a[i]].pb(mp(i,mp(i,1)));
            mn=min(mn,a[i]);
        }
    for (int i=mn; i<=2000; i++)
    {
        sort(v[i].begin(),v[i].end());
        int l1=v[i][0].ff,r1=v[i][0].ss.ff,kk=v[i][0].ss.ss;
        for (int j=1; j<v[i].size(); j++)
        {
            if (v[i][j].ff==r1+1)
            {
                r1=v[i][j].ss.ff;
                kk+=v[i][j].ss.ss;
            } else
            {
                if (kk%2==1) {res=0; break;}
                v[i+1].pb(mp(l1,mp(r1,kk/2)));
                l1=v[i][j].ff;
                r1=v[i][j].ss.ff;
                kk=v[i][j].ss.ss;
            }
        }
        if (l1==l&&r1==r&&kk==1&&res==1)
        {
            v[i].clear();
            v[i+1].clear();
            break;
        }
        if (kk%2==1) res=0; else v[i+1].pb(mp(l1,mp(r1,kk/2)));
        if (res==0) {v[i].clear(); v[i+1].clear(); break;}
        v[i].clear();
    }
    for (int i=l; i<=r; i++)
    {
        v[a[i]].clear();
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=n; i++)
    {
        dp[i]=dp[i-1]+1;
        for (int l=1; l<=i; l++)
            if (can(l,i)) dp[i]=min(dp[i],dp[l-1]+1);
    }
    cout<<dp[n];
}
/**

4 3 2 2 3 2 2 4
**/