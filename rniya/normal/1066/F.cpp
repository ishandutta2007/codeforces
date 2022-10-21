#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF=1e18;

int dist(pair<int,int> p,pair<int,int> q){
    return abs(p.first-q.first)+abs(p.second-q.second);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<pair<int,int>> pos;
    map<int,vector<pair<int,int>>> lev;
    for (int i=0;i<n;++i){
        int x,y; cin >> x >> y;
        pos.emplace_back(x,y);
        lev[max(x,y)].emplace_back(pos[i]);
    }
    int N=lev.size(),i=0;
    vector<vector<ll>> dp(N+1,vector<ll>(2,INF));
    vector<vector<pair<int,int>>> pre(N+1,vector<pair<int,int>>(2));
    dp[0][0]=dp[0][1]=0;
    pre[0][0]=pre[0][1]={0,0};
    for (auto x:lev){
        auto v=x.second; int l=x.first;
        sort(v.begin(),v.end(),[&](auto p,auto q){
            if (p.first==l&&q.first==l) return p.second<q.second;
            if (p.first==l&&q.first!=l) return p>q;
            if (p.first!=l&&q.first!=l) return q.first<p.first;
        });
        pre[i+1][0]=v[0];
        pre[i+1][1]=v.back();
        for (int j=0;j<2;++j){
            for (int k=0;k<2;++k){
                dp[i+1][j]=min(dp[i+1][j],dp[i][k]+dist(pre[i][k],pre[i+1][j^1])+dist(pre[i+1][j^1],pre[i+1][j]));
            }
        }
        ++i;
    }
    cout << min(dp[N][0],dp[N][1]) << '\n';
}