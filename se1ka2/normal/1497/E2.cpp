#include <functional>
#include <iostream>
#include <vector>
using namespace std;

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
        while(n <= nn) n <<= 1;
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

std::vector<int> enum_prime(int n){     // containing n
    std::vector<int> res;
    if (n <= 1) return res;
    std::vector<bool> p(n + 1);
    fill(p.begin() + 2, p.end(), true);
    for(int i = 2; i <= n; i++){
        if(p[i]){
            res.push_back(i);
            for(int j = i * 2; j <= n; j += i) p[j] = false;
        }
    }
    return res;
}

int b[10000005];
int a[200005];
int r[200005];
int dp[200005][22];

int main()
{
    int t;
    cin >> t;
    vector<int> prime = enum_prime(4000);
    for(int i = 0; i <= 10000000; i++) b[i] = 1000000;
    while(t--){
        int n, k;
        cin >> n >> k;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            for(int p : prime){
                if(p * p > a[i]) break;
                while(a[i] % (p * p) == 0) a[i] /= p * p;
            }
        }
        for(int i = n - 1; i >= 0; i--){
            r[i] = b[a[i]];
            b[a[i]] = i;
        }
        for(int i = 0; i < n; i++) b[a[i]] = 1000000;
        SegmentTree<int> seg(n, [](int a, int b){return min(a, b);}, 1000000);
        for(int i = 0; i < n; i++) seg.set(i, r[i]);
        seg.build();
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= k; j++) dp[i][j] = n;
            int l = i;
            for(int j = 0; j <= k; j++){
                if(l >= 0) l = seg.left_bound(l, [&](int a){return a < i;});
                for(int o = j; o <= k; o++) dp[i][o] = min(dp[i][o], dp[l + 1][o - j] + 1);
            }
        }
        cout << dp[n][k] << endl;
    }
}