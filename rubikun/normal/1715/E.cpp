#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=998244353,MAX=100005;
const ll INF=1LL<<60;

/**
 * Author: Simon Lindholm
 * Date: 2017-04-20
 * License: CC0
 * Source: own work
 * Description: Container where you can add lines of the form kx+m, and query maximum values at points x.
 *  Useful for dynamic programming (``convex hull trick'').
 * Time: O(\log N)
 * Status: stress-tested
 */
#pragma once

struct Line {
    mutable ll k, m, p;
    bool operator<(const Line& o) const { return k < o.k; }
    bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
    // (for doubles, use inf = 1/.0, div(a,b) = a/b)
    static const ll inf = LLONG_MAX;
    ll div(ll a, ll b) { // floored division
        return a / b - ((a ^ b) < 0 && a % b); }
    bool isect(iterator x, iterator y) {
        if (y == end()) return x->p = inf, 0;
        if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
        else x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    void add(ll k, ll m) {
        auto z = insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }
    ll query(ll x) {
        assert(!empty());
        auto l = *lower_bound(x);
        return l.k * x + l.m;
    }
};

vector<pair<int,ll>> G[MAX];
ll dis[MAX],dp[MAX];

int N;

void dijkstra(){
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> PQ;
    
    for(int i=0;i<N;i++){
        PQ.push(mp(dis[i],i));
    }
    
    while(!PQ.empty()){
        ll a=PQ.top().first;
        int b=PQ.top().second;
        PQ.pop();
        if(dis[b]<a) continue;
        for(int i=0;i<G[b].size();i++){
            int c=G[b][i].first;
            ll d=G[b][i].second;
            if(dis[c]>dis[b]+d){
                dis[c]=dis[b]+d;
                PQ.push(make_pair(dis[c],c));
            }
        }
    }
    return;
}//a,d

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N;
    int M,K;cin>>M>>K;
    for(int i=0;i<M;i++){
        int a,b,c;cin>>a>>b>>c;a--;b--;
        G[a].push_back(mp(b,c));
        G[b].push_back(mp(a,c));
    }
    
    for(int i=0;i<N;i++) dis[i]=INF;
    dis[0]=0;
    vector<ll> ans(N,INF);
    for(int t=0;t<=K;t++){
        dijkstra();
        for(int i=0;i<N;i++) chmin(ans[i],dis[i]);
        
        if(t==K) break;
        
        for(int i=0;i<N;i++) dp[i]=dis[i];
        
        {
            LineContainer CHT;
            for(ll i=0;i<N;i++){
                if(i) chmin(dp[i],-CHT.query(i)+i*i);
                CHT.add(2*i,-i*i-dis[i]);
            }
        }
        {
            LineContainer CHT;
            for(ll i=N-1;i>=0;i--){
                if(i<N-1) chmin(dp[i],-CHT.query(i)+i*i);
                CHT.add(2*i,-i*i-dis[i]);
            }
        }
        
        for(int i=0;i<N;i++){
            chmin(ans[i],dp[i]);
            dis[i]=dp[i];
        }
    }
    
    for(int i=0;i<N;i++) cout<<ans[i]<<" ";
    cout<<endl;
}