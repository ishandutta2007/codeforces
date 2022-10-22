#include <functional>
#include <iostream>
#include <vector>
#include <set>
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

int main()
{
    int n;
    cin >> n;
    int b[200005];
    for(int i = 0; i < n * 2; i++) b[i] = -1;
    int d[100005];
    set<int> st;
    int c = 0;
    for(int i = 0; i < n * 2; i++){
        char t;
        cin >> t;
        if(t == '+'){
            st.insert(i);
            b[i] = c++;
        }
        else{
            int x;
            cin >> x;
            x--;
            d[x] = i;
        }
    }
    int ans[100005];
    SegmentTree<int> seg(n * 2, [](int a, int b){return max(a, b);}, -1);
    for(int i = 0; i < n; i++) seg.set(d[i], i);
    seg.build();
    for(int i = 0; i < n; i++){
        auto itr = st.lower_bound(d[i]);
        if(itr == st.begin()){
            cout << "NO" << endl;
            return 0;
        }
        itr--;
        if(seg.query(*itr, d[i]) > i){
            cout << "NO" << endl;
            return 0;
        }
        ans[b[*itr]] = i;
        st.erase(itr);
    }
    cout << "YES" << endl;
    for(int i = 0; i < n; i++) cout << ans[i] + 1 << " ";
    cout << endl;
}