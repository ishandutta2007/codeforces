#include <functional>
#include <iostream>
#include <queue>
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

int left(int i, int *l){
    if(i == -1) return -1;
    if(l[i] == i) return i;
    return left(l[i], l);
}

int main()
{
    int n;
    cin >> n;
    int k = 0;
    ll a[200005];
    int p[200005];
    priority_queue<P> que;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] >= 0) p[k++] = i;
        else que.push(P(a[i], i));
    }
    SegmentTree<ll> seg(k, [](ll a, ll b){return a + b;}, 0);
    for(int i = 0; i < k; i++) seg.set(i, a[p[i]]);
    seg.build();
    int l[200005];
    for(int i = 0; i <= k; i++) l[i] = i;
    int ans = k;
    while(que.size()){
        int i = que.top().second;
        que.pop();
        int j = lower_bound(p, p + k, i) - p;
        if(seg.query(0, j) + a[i] >= 0){
            ans++;
            j = min(j - 1, left(j, l));
            while(true){
                ll r = min(seg[j], abs(a[i]));
                seg.update(j, seg[j] - r);
                a[i] += r;
                if(a[i] == 0) break;
                else{
                    l[j] = min(l[j], j - 1);
                    j = left(j, l);
                }
            }
        }
    }
    cout << ans << endl;
}