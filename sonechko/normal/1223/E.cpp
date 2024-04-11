#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 6e5 + 11;

ll dp[N][2];
int n,k;
vector<pair<int,ll> > v[N];

void dfs(int l, int pr)
{
    vector<pair<int,ll> > vs;
    for (int j=0; j<v[l].size(); j++)
        if (v[l][j].ff!=pr) {dfs(v[l][j].ff,l); vs.pb(v[l][j]);}
    ll sum=0;
    vector<ll> vtt;
    for (int j=0; j<vs.size(); j++)
    {
        int to=vs[j].ff;
        ll ww=vs[j].ss;
        ll x1=dp[to][0];
        ll x2=dp[to][1]+ww;
        sum+=x1;
        if (x2>x1) vtt.pb(x2-x1);
    }
    ll sum1=sum,sum2=sum;
    sort(vtt.begin(),vtt.end());
    reverse(vtt.begin(),vtt.end());
    for (int j=0; j<vtt.size(); j++)
    {
        if (j<k) sum1+=vtt[j];
        if (j<k-1) sum2+=vtt[j];
    }
    ///cout<<l<<" "<<sum1<<" "<<sum2<<endl;
    dp[l][0]=sum1;
    dp[l][1]=sum2;
}

void up()
{
    cin>>n>>k;
    for (int i=1; i<=n; i++)
    {
        dp[i][0]=0;
        dp[i][1]=0;
        v[i].clear();
    }
    for (int i=1; i<n; i++)
    {
        int l,r,p;
        cin>>l>>r>>p;
        v[l].pb(mp(r,p));
        v[r].pb(mp(l,p));
    }
    dfs(1,0);
    cout<<dp[1][0]<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin>>q;
    while (q--)
        up();
}
/**
dp i 0
dp i 1
**/