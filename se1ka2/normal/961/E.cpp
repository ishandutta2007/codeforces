#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

template <typename T>
struct BIT
{
    int n;
    vector<T> bit;
    
    BIT(){}
    
    BIT(int n) : n(n){
        bit.resize(n + 1);
    }
    
    T sum(int i){
        i++;
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
    int n;
    cin >> n;
    BIT<ll> bit(n);
    vector<int> v[200005];
    int a[200005];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i]--;
        if(a[i] >= n) bit.add(i, 1);
        else v[a[i]].push_back(i);
    }
    ll ans = 0;
    for(int i = n - 1; i >= 0; i--){
        for(int x : v[i]) bit.add(x, 1);
        ans += max(0ll, bit.sum(min(a[i], n - 1)) - bit.sum(i));
    }
    cout << ans << endl;
}