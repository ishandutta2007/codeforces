#include <functional>
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

const ll INF = 100000000000000;

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

int f(int l, int r, ll *a){
    priority_queue<P, vector<P>, greater<P>> que;
    for(int i = l + 1; i < r; i++){
        que.push(P((a[i] - a[l]) - (i - l), i - l));
    }
    que.push(P(0, 0));
    que.push(P((a[r] - a[l]) - (r - l), r - l));
    bool start = false;
    SegmentTree<int> seg(r - l + 1, [](int a, int b){return max(a, b);}, 0);
    while(que.size()){
        P p = que.top();
        que.pop();
        int i = p.second;
        if(i == r - l){
            return seg.query(0, r - l);
        }
        if(i == 0) start = true;
        if(!start) continue;
        seg.update(i, seg.query(0, i) + 1);
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    ll a[500005];
    for(int i = 1; i <= n; i++) cin >> a[i];
    a[0] = -INF;
    a[n + 1] = INF;
    int b[500005];
    for(int i = 1; i <= k; i++) cin >> b[i];
    b[0] = 0;
    b[k + 1] = n + 1;
    int ans = n + 1;
    for(int i = 0; i <= k; i++){
        if(a[b[i + 1]] - a[b[i]] < b[i + 1] - b[i]){
            cout << -1 << endl;
            return 0;
        }
        ans -= f(b[i], b[i + 1], a);
    }
    cout << ans << endl;
}