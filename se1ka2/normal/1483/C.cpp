#include <functional>
#include <iostream>
#include <stack>
using namespace std;
typedef long long ll;

const ll INF = 10000000000000000;

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

int main()
{
    int n;
    cin >> n;
    int h[300005], q[300005];
    for(int i = 0; i < n; i++){
        cin >> h[i];
        h[i]--;
        q[h[i]] = i;
    }
    ll b[300005];
    for(int i = 0; i < n; i++) cin >> b[i];
    SegmentTree<int> lf(n, [](int a, int b){return max(a, b);}, -1);
    int left[300005];
    for(int i = 0; i < n; i++){
        left[q[i]] = lf.query(0, q[i]);
        lf.update(q[i], q[i]);
    }
    SegmentTree<ll> seg0(n + 1, [](ll a, ll b){return max(a, b);}, -INF);
    SegmentTree<ll> seg1(n, [](ll a, ll b){return max(a, b);}, -INF);
    seg0.update(0, 0);
    stack<int> st;
    for(int i = 0; i < n; i++){
        seg0.update(i + 1, max(seg0.query(left[i] + 1, i + 2), seg1.query(0, n)) + b[i]);
        seg1.update(i, seg0[i + 1]);
        while(!st.empty() && st.top() > h[i]){
            seg1.update(q[st.top()], -INF);
            st.pop();
        }
        st.push(h[i]);
    }
    cout << max(seg0[n], seg1.query(0, n)) << endl;
}