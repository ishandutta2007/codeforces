#include <algorithm>
#include <iostream>
#include <vector>
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
        P p[305];
        for(int i = 0; i < m; i++){
            int a;
            cin >> a;
            p[i] = P(a, -i);
        }
        sort(p, p + m);
        BIT<int> bit(m);
        int ans = 0;
        for(int i = 0; i < m; i++){
            ans += bit.sum(-p[i].second);
            bit.add(-p[i].second, 1);
        }
        cout << ans << endl;
    }
}