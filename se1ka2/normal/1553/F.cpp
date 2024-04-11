#include <functional>
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
    
    T sum(int i){   // sum of [0, i)
        T res = 0;
        while(i){
            res += bit[i];
            i -= (i & -i);
        }
        return res;
    }
    
    T query(int l, int r){
        return sum(r) - sum(l);
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    BIT<ll> sum(300001);
    BIT<ll> cnt(300001);
    ll ans = 0;
    bool b[300001]{0};
    for(int i = 0; i < n; i++){
        ll a;
        cin >> a;
        ans += a * cnt.query(a, 300001);
        ans += sum.query(0, a);
        for(int k = 1; k * a <= 300000; k++){
            ll s = sum.query(k * a, min(300001ll, (k + 1) * a));
            ans += s - cnt.query(k * a, min(300001ll, (k + 1) * a)) * k * a;
        }
        int r = a;
        for(int k = 1; k <= 100; k++){
            int l = a / (k + 1) + 1;
            if(r - l < 10){
                for(int j = l; j < r; j++){
                    if(b[j]) ans += a - j * k;
                }
            }
            else ans += a * cnt.query(l, r) - sum.query(l, r) * k;
            r = l;
        }
        for(int i = 0; i < r; i++){
            if(b[i]) ans += a % i;
        }
        sum.add(a, a);
        cnt.add(a, 1);
        b[a] = true;
        cout << ans << " ";
    }
    cout << "\n";
}