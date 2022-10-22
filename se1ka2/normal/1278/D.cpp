#include <functional>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
 
template< typename T >
struct BinaryIndexedTree {
  vector< T > data;
 
  BinaryIndexedTree(int sz) {
    data.assign(++sz, 0);
  }
 
  T sum(int k) {
    T ret = 0;
    for(++k; k > 0; k -= k & -k) ret += data[k];
    return (ret);
  }
 
  void add(int k, T x) {
    for(++k; k < (int)data.size(); k += k & -k) data[k] += x;
  }
};
 
class UnionFind
{
    vector<int> par, rank;
    
public:
    UnionFind(int n){
        par.resize(n);
        rank.resize(n);
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
        return par[i] == par[j];
    }
    
    void unite(int i, int j){
        if(same(i, j)) return;
        i = find(i), j = find(j);
        if(rank[i] < rank[j]) par[i] = j;
        else{
            par[j] = i;
            if(rank[i] == rank[j]) rank[i]++;
        }
    }
};
 
int l[500004], r[500004];
int d[1000003], e[1000003];
P p[500004];
 
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        scanf("%d %d", &l[i], &r[i]);
        p[i] = P(l[i], r[i]);
    }
    sort(p, p + n);
    for(int i = 0; i < n; i++){
        d[p[i].first] = i + 1;
        e[p[i].second] = i + 1;
    }
    ll t = 0;
    BinaryIndexedTree<int> bit(n + 1);
    for(int i = 0; i <= n * 2; i++){
        if(d[i]) bit.add(d[i], 1);
        if(e[i]){
            bit.add(e[i], -1);
            t += bit.sum(n) - bit.sum(e[i]);
        }
    }
    if(t != n - 1){
        cout << "NO" << endl;
        return 0;
    }
    UnionFind uf(n + 1);
    set<int> st;
    for(int i = 0; i <= n * 2; i++){
        if(d[i]) st.insert(d[i]);
        if(e[i]){
            for(auto itr = st.rbegin(); itr != st.rend(); itr++){
                if(*itr == e[i]) break;
                uf.unite(e[i], *itr);
            }
            st.erase(e[i]);
        }
    }
    int k = 0;
    for(int i = 1; i <= n; i++) if(uf.find(i) == i) k++;
    if(k == 1) cout << "YES" << endl;
    else cout << "NO" << endl;
}