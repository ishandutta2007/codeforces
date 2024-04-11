#include <functional>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

template <typename T>
struct SegmentTree
{
    using F = function<T(T, T)>;
    
    const F f;
    const T e;
    
    int n;
    vector<T> seg;
    
    SegmentTree(int nn, const F f, const T e) : f(f), e(e){
        n = 1;
        while(n < nn) n <<= 1;
        seg.assign(n * 2, e);
    }
    
    void set(int i, T x){
        seg[i + n] = x;
    }
    
    void build(){
        for(int k = n - 1; k > 0; k--){
            seg[k] = f(seg[k * 2], seg[k * 2 + 1]);
        }
    }
    
    void update(int i, T x){
        int k = i + n;
        seg[k] = x;
        while(k >>= 1){
            seg[k] = f(seg[k * 2], seg[k * 2 + 1]);
        }
    }
    
    T query(int l, int r){
        l += n, r += n;
        T L = e, R = e;
        for(; l != r; l >>= 1, r >>= 1){
            if(l % 2) L = f(L, seg[l++]);
            if(r % 2) R = f(seg[--r], R);
        }
        return f(L, R);
    }
    
    T operator[](const int i)const {
        return seg[i + n];
    }
    
    template<typename C>
    int right_bound_sub(int k, const C &check, T x){
        while(k < n){
            if(check(f(x, seg[k * 2]))){
                k = k * 2;
            }
            else{
                x = f(x, seg[k * 2]);
                k = k * 2 + 1;
            }
        }
        return k - n;
    }
    
    template <typename C>
    int right_bound(int i, const C &check){
        T x = e;
        for(int l = i + n, r = n * 2; l != r; l >>= 1, r >>= 1){
            if(l % 2){
                if(check(f(x, seg[l]))){
                    return right_bound_sub(l, check, x);
                }
                x = f(x, seg[l]);
                l++;
            }
        }
        return -1;
    }
    
    template <typename C>
    int left_bound_sub(int k, const C &check, T x){
        while(k < n){
            if(check(f(seg[k * 2 + 1], x))){
                k = k * 2 + 1;
            }
            else{
                x = f(seg[k * 2 + 1], x);
                k = k * 2;
            }
        }
        return k - n;
    }
    
    template <typename C>
    int left_bound(int i, const C &check){
        T x = e;
        for(int l = n, r = i + n; l != r; l >>= 1, r >>= 1){
            if(r % 2){
                if(check(f(seg[--r], x))){
                    return left_bound_sub(r, check, x);
                }
                x = f(x, seg[r]);
            }
        }
        return -1;
    }
};

int main()
{
    string s;
    cin >> s;
    ll x, y;
    cin >> x >> y;
    if(x < y){
        swap(x, y);
        reverse(s.begin(), s.end());
    }
    int n = s.size();
    SegmentTree<ll> z(n, [](ll a, ll b){return a + b;}, 0);
    SegmentTree<ll> o(n, [](ll a, ll b){return a + b;}, 0);
    for(int i = 0; i < n; i++){
        if(s[i] == '1') o.set(i, 1);
        else z.set(i, 1);
    }
    o.build();
    z.build();
    ll t = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '1') t += z.query(0, i) * x;
        else t += o.query(0, i) * y;
    }
    ll ans = t;
    for(int i = 0; i < n; i++){
        if(s[i] == '?'){
            t += z.query(0, i) * x;
            t += z.query(i + 1, n) * y;
            t -= o.query(0, i) * y;
            t -= o.query(i + 1, n) * x;
            z.update(i, 0);
            o.update(i, 1);
            ans = min(ans, t);
        }
    }
    cout << ans << endl;
}