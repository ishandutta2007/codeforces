#include <functional>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, int> P;

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

ll a[500005];
ll s[500005];
P p[500005];
int q[500005];
int dp[500005];

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i - 1];
        for(int i = 0; i <= n; i++) p[i] = P(s[i], i);
        sort(p, p + n + 1);
        for(int i = 0; i <= n; i++) q[p[i].second] = i;
        SegmentTree<int> segp(n + 1, [](int a, int b){return max(a, b);}, -1000000000);
        SegmentTree<int> seg0(n + 1, [](int a, int b){return max(a, b);}, -1000000000);
        dp[0] = 0;
        segp.update(q[0], 0);
        seg0.update(q[0], 0);
        for(int i = 1; i <= n; i++){
			dp[i] = dp[i - 1] - 1;
            int j = upper_bound(p, p + n + 1, P(s[i], -1)) - p;
            dp[i] = max(dp[i], segp.query(0, j) + i);
			int k = upper_bound(p, p + n + 1, P(s[i], n + 1)) - p;
			dp[i] = max(dp[i], seg0.query(j, k));
            segp.update(q[i], dp[i] - i);
			seg0.update(q[i], dp[i]);
        }
        cout << dp[n] << endl;
    }
}