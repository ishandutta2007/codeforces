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
int l[200005];
int dp[200005];

int main()
{
    int t;
    cin >> t;
    vector<int> prime = enum_prime(4000);
    for(int i = 0; i <= 10000000; i++) b[i] = -1;
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
        for(int i = 0; i < n; i++){
            l[i] = b[a[i]];
            b[a[i]] = i;
        }
        for(int i = 0; i < n; i++) b[a[i]] = -1;
        SegmentTree<int> seg(n, [](int a, int b){return max(a, b);}, -1);
        for(int i = 0; i < n; i++) seg.set(i, l[i]);
        seg.build();
        dp[0] = 0;
        for(int i = 1; i <= n; i++){
            int left = -1, right = i - 1;
            while(right - left > 1){
                int mid = (right + left) / 2;
                if(seg.query(mid, i) >= mid) left = mid;
                else right = mid;
            }
            dp[i] = dp[right] + 1;
        }
        cout << dp[n] << endl;
    }
}