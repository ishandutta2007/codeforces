#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
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
        int n;
        cin >> n;
        int a[200005];
        for(int i = 0; i < n; i++) cin >> a[i];
        map<int, int> mp;
        for(int i = 0; i < n; i++) mp[a[i]]++;
        int k = 0;
        for(P p : mp) mp[p.first] = k++;
        BIT<int> bit(k);
        ll ans = 0;
        for(int i = 0; i < n; i++){
            int l = bit.sum(mp[a[i]]);
            int r = i - bit.sum(mp[a[i]] + 1);
            ans += min(r, l);
            bit.add(mp[a[i]], 1);
        }
        cout << ans << endl;
    }
}