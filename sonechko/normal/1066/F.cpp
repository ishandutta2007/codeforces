#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;

map<int,int> mt;
int kol;
vector<pair<ll,ll> > v[N];
ll dp[N][2];

ll dist(pair<ll,ll> a, pair<ll,ll> b)
{
    return abs(a.ff-b.ff)+abs(a.ss-b.ss);
}

bool cmp(pair<ll,ll> a, pair<ll,ll> b)
{
    if (a.ff<b.ff) return true;
    if (a.ff>b.ff) return false;
    if (a.ss>b.ss) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    vector<ll> vv;
    for (int i=1; i<=n; i++)
    {
        ll l,r;
        cin>>l>>r;
        ll c=max(l,r);
        if (mt[c]==0) {kol++; mt[c]=kol; vv.pb(c);}
        v[mt[c]].pb(mp(l,r));
    }
    vv.pb(0);
    kol++;
    mt[0]=kol;
    v[kol].pb(mp(0,0));
    sort(vv.begin(),vv.end());
    for (int i=0; i<vv.size(); i++)
    {
        dp[i][0]=2e18;
        dp[i][1]=2e18;
    }
    dp[0][0]=0;
    dp[0][1]=0;
    for (int i=1; i<vv.size(); i++)
    {
        int t1=mt[vv[i-1]];
        int t2=mt[vv[i]];
        //cout<<i<<": "<<endl;
        //for (int i=0; i<v[t2].size(); i++)
        //    cout<<v[t2][i].ff<<" "<<v[t2][i].ss<<endl;
        //cout<<endl;
        sort(v[t2].begin(),v[t2].end(),cmp);
        dp[i][0]=min(dp[i-1][1]+dist(v[t1].back(),v[t2].back()),
                     dp[i-1][0]+dist(v[t1][0],v[t2].back()));
        dp[i][0]+=dist(v[t2][0],v[t2].back());
        dp[i][1]=min(dp[i-1][1]+dist(v[t1].back(),v[t2][0]),
                     dp[i-1][0]+dist(v[t1][0],v[t2][0]));
        dp[i][1]+=dist(v[t2][0],v[t2].back());
        //cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
    }
    cout<<min(dp[vv.size()-1][0],dp[vv.size()-1][1]);
}


/**
0 3
1 3
2 3
3 3
3 2
3 1
3 0
**/