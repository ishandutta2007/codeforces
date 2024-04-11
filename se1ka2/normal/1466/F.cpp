#include <functional>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, bool> P;

const ll MOD = 1000000007;

template <typename S>   //semi group
struct UnionFind
{
    using F = std::function<S(S, S)>;
    
    const F f;
    
    std::vector<int> par, rank;
    std::vector<S> dat;
    
    UnionFind(int n, const F f, const S e) : f(f){
        par.resize(n);
        rank.resize(n);
        dat.assign(n, e);
        for(int i = 0; i < n; i++){
            par[i] = i;
            rank[i] = 0;
        }
    }
    
    int find(int i){
        if(i == par[i]) return i;
        return par[i] = find(par[i]);
    }
    
    bool same(int i, int j){
        return find(i) == find(j);
    }
    
    void unite(int i, int j){
        i = find(i), j = find(j);
        if(i == j) return;
        if(rank[i] < rank[j]) std::swap(i, j);
        par[j] = i;
        dat[i] = f(dat[i], dat[j]);
        if(rank[i] == rank[j]) rank[i]++;
    }
    
    S query(int i){
        return dat[find(i)];
    }
};

vector<int> v[500005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        for(int j = 0; j < k; j++){
            int x;
            cin >> x;
            x--;
            v[i].push_back(x);
        }
    }
    UnionFind<P> uf(m, [](P a, P b){return P(a.first + b.first, a.second | b.second);}, P(1, false));
    vector<int> ans;
    for(int i = 0; i < n; i++){
        if(v[i].size() == 2){
            if(uf.same(v[i][0], v[i][1]) || (uf.query(v[i][0]).second && uf.query(v[i][1]).second)) continue;
            ans.push_back(i);
            uf.unite(v[i][0], v[i][1]);
        }
        else{
            if(uf.query(v[i][0]).second) continue;
            ans.push_back(i);
            uf.dat[uf.find(v[i][0])].second = true;
        }
    }
    ll s = 1;
    int l = ans.size();
    for(int i = 0; i < l; i++) s = s * 2 % MOD;
    cout << s << " " << l << "\n";
    for(int x : ans) cout << x + 1 << " ";
    cout << "\n";
}