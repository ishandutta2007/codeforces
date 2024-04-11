#include<bits/stdc++.h>
using namespace std;
long long p[100009], d[100009], l[100009], f[100009], w[100009];
multiset<pair<long long,long long> > S[100009];
vector<long long> v[100009];
void Un(long long x, long long y){
    if(x == y) return;
    for(auto it = S[y].begin(); it != S[y].end(); ++it){
        S[x].insert(*it);
    }
}
void U(long long x, long long y){
    if(S[l[x]].size() > S[l[y]].size()){
        Un(l[x], l[y]);
    }
    else{
        Un(l[y], l[x]);
        l[x] = l[y];
    }
}
void dfs(long long x){
    for(auto y : v[x]){
        dfs(y);
        U(x, y);
    }
    auto it = S[l[x]].lower_bound({d[x]+1,-1});
    while(it != S[l[x]].end() && it->second < w[x]){
        long long K = it->second;
        S[l[x]].erase(it);
        it = S[l[x]].lower_bound({d[x]+1,-1});
        if(it != S[l[x]].end()){
            auto X = *it;
            X.second += K;
            S[l[x]].erase(it);
            S[l[x]].insert(X);
            it = S[l[x]].lower_bound({d[x]+1,-1});
        }
    }
    if(it != S[l[x]].end()) {
        auto X = *it;
            X.second -= w[x];
            S[l[x]].erase(it);
            S[l[x]].insert(X);
        }
    S[l[x]].insert({d[x], w[x]});
}
main(){
    long long n, m, k;
    cin >> n >> m >> k;
    for(long long i =1 ;i <= n; i++)
        l[i] = i;
    for(long long i = 2; i <= n; i++){
        cin >> p[i];
        v[p[i]].push_back(i);
    }
    for(long long i = 1; i <= m; i++){
        long long V,D,W;
        cin >> V >> D >> W;
        d[V] = D;
        w[V] = W;
    }
    dfs(1);
    long long ans = 0;
    for(auto it = S[l[1]].begin(); it != S[l[1]].end(); it++){
        ans += it->second;
    }
    cout << ans << endl;
}