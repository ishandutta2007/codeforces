#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using l_l = pair<ll, ll>;
ll N, M;
vector<ll> a, k;
vector<ll> del;
vector<ll> P;

vector<l_l> Q;
struct UF{
    int n;
    vector<int> par,size;
    
    void init(int n_){
        n=n_;
        par.assign(n,-1);
        size.assign(n,1);
        
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }
    
    int root(int a){
        if(par[a]==a) return a;
        else return par[a]=root(par[a]);
    }
    
    void unite(int a,int b){
        if(root(a)!=root(b)){
            size[root(a)]+=size[root(b)];
            par[root(b)]=root(a);
        }
    }
    
    bool check(int a,int b){
        return root(a)==root(b);
    }
};

ll ans[201000];
 

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N >> M;
    a.resize(N);
    del.resize(N);
    k.resize(M);
    P.push_back(0);
    for(int i = 0; i < N; i++) cin >> a[i];
    for(int i = 0; i < M; i++) cin >> k[i];
    vector<ll> asum(N + 1);
    for(int i = 0; i < N; i++) {
        asum[i+1] = asum[i] + a[i];
    }
    for(int i = 0; i < N; i++) {
        while(P.size() >= 2) {
            ll sz = P.size();
            __int128_t dx1 = P[sz-1] - P[sz-2];
            __int128_t dy1 = asum[P[sz-1]] - asum[P[sz-2]];
            __int128_t dx2 = i + 1 - P[sz-2];
            __int128_t dy2 = asum[i+1] - asum[P[sz-2]];
            if(dy1 * dx2 < dy2 * dx1) break;
            else P.pop_back();
        }
        ll sz = P.size();
        __int128_t dx = i + 1 - P[sz-1];
        __int128_t dy = asum[i+1] - asum[P[sz-1]];
        del[i] = (dy + dx - 1) / dx;
        //cerr << del[i] << " ";
        P.push_back(i + 1);
        if(i != N - 1) Q.push_back({del[i], i});
    }
    //cerr << endl;
    sort(Q.begin(), Q.end(), greater<l_l>());
    UF uni;
    uni.init(N);
    ll idx = 0;
    ll nowans = 1;
    for(int i = M - 1; i >= 0; i--) {
        while(idx < Q.size() and Q[idx].first > k[i]) {
            uni.unite(Q[idx].second, Q[idx].second + 1);
            ll r = uni.root(Q[idx].second);
            nowans = max(nowans, (ll)uni.size[r]);
            idx++;
        }
        ans[i] = nowans;
    }
    for(int i = 0; i < M; i++) {
        if(i != 0) cout << " ";
        cout << ans[i] - 1;
    }
    cout << endl;
    return 0;
}