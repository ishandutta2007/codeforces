#include<bits/stdc++.h>
using namespace std;



#define ll long long
#define ss second
#define ff first
#define endl "\n"
#define ld long double
#define ull unsigned long long
#define mp make_pair
#define pb push_back



const int N = 2e6 + 11;
const ll MOD = 1e9 + 7;
#define mod %MOD
ll dp1[N],dp2[N],a1[N],a2[N];
vector<ll> v1[N],cost1[N],v2[N],cost2[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    int M = 1e6;
    for (int i=1; i<=m; i++)
    {
        ll p,l,r,cost;
        cin>>p>>l>>r>>cost;
        if (r==0) {v1[p].pb(l); cost1[p].pb(cost);}
        if (l==0) {v2[p].pb(r); cost2[p].pb(cost);}
    }
    ll kol=0,sum=0;
    for (int i=1; i<=M; i++)
    {
        for (int j=0; j<v1[i].size(); j++)
        {
            ll l=v1[i][j],cost=cost1[i][j];
            if (a1[l]==0)
            {
                kol++;
                sum+=cost;
                a1[l]=cost;
            } else
            if (a1[l]>cost)
            {
                sum-=a1[l];
                a1[l]=cost;
                sum+=a1[l];
            }
        }
        if (kol==n) dp1[i]=sum; else dp1[i]=-1;
    }
    kol=0;
    sum=0;
    for (int i=M; i>=1; i--)
    {
        for (int j=0; j<v2[i].size(); j++)
        {
            ll l=v2[i][j],cost=cost2[i][j];
            if (a2[l]==0)
            {
                kol++;
                sum+=cost;
                a2[l]=cost;
            } else
            if (a2[l]>cost)
            {
                sum-=a2[l];
                a2[l]=cost;
                sum+=a2[l];
            }
        }
        if (kol==n) dp2[i]=sum; else dp2[i]=-1;
    }
    ll ans=4e18;
    for (int j=1; j<=M; j++)
        if (dp1[j-1]>0&&dp2[j+k]>0) ans=min(ans,dp1[j-1]+dp2[j+k]);
    if (ans==4000000000000000000) cout<<-1<<endl; else cout<<ans<<endl;

}