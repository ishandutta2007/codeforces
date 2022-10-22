#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef pair<int, int> P;

template <typename T>
struct BIT
{
    int n;
    vector<T> bit;
    
    BIT(){}
    
    BIT(int n) : n(n){
        bit.resize(n + 1);
    }
    
    T sum(int i){   // sum of [0, i)
        T res = 0;
        while(i){
            res += bit[i];
            i -= (i & -i);
        }
        return res;
    }
    
    void add(int i, T x){
        i++;
        while(i <= n){
            bit[i] += x;
            i += (i & -i);
        }
    }
};

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int a[90005];
        int b[90005];
        for(int i = 0; i < n * m; i++){
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b, b + n * m);
        map<int, vector<P>> v;
        for(int i = 0; i < n * m; i++) v[b[i]].push_back(P(-i / m, i % m));
        for(auto itr = v.begin(); itr != v.end(); itr++){
            sort(v[itr->first].begin(), v[itr->first].end());
        }
        vector<BIT<int>> bit(n, BIT<int>(m));
        int ans = 0;
        for(int i = 0; i < n * m; i++){
            P p = v[a[i]].back();
            v[a[i]].pop_back();
            ans += bit[-p.first].sum(p.second);
            bit[-p.first].add(p.second, 1);
        }
        cout << ans << endl;
    }
}