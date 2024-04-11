#include <functional>
#include <iostream>
#include <vector>
using namespace std;

struct PrimeDecomposition
{
    int n;
    vector<bool> p;
    vector<int> prime;
    vector<int> d;
    
    PrimeDecomposition(int n) : n(n){
        p.resize(n + 1);
        d.resize(n + 1);
        d[1] = 1;
        for(int i = 2; i <= n; i++){
            if(!p[i]){
                prime.push_back(i);
                for(int j = i; j <= n; j += i){
                    if(!p[j]) d[j] = i;
                    p[j] = true;
                }
            }
        }
    }
    
    vector<int> decomposition(int x){
        vector<int> res;
        while(x > 1){
            res.push_back(d[x]);
            x /= d[x];
        }
        return res;
    }
};

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

int rh[22][100005];
int a[100005];
int last[100005];

int main()
{
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> a[i];
    SegmentTree<int> seg(n, [](int a, int b){return min(a, b);}, n);
    PrimeDecomposition pd(100000);
    for(int i = 0; i <= 100000; i++) last[i] = -1;
    for(int i = 0; i < n; i++){
        vector<int> d = pd.decomposition(a[i]);
        for(int p : d){
            if(last[p] != -1 && last[p] < i) seg.set(last[p], min(seg[last[p]], i));
            last[p] = i;
        }
    }
    seg.build();
    for(int i = 0; i < n; i++){
        rh[0][i] = seg[i];
        rh[0][i] = seg.query(i, rh[0][i]);
    }
    rh[0][n] = n;
    for(int j = 1; j <= 20; j++){
        for(int i = 0; i <= n; i++) rh[j][i] = rh[j - 1][rh[j - 1][i]];
    }
    while(q--){
        int l, r;
        cin >> l >> r;
        l--;
        int ans = 0;
        for(int j = 20; j >= 0; j--){
            if(rh[j][l] < r){
                ans += (1 << j);
                l = rh[j][l];
            }
        }
        cout << ans + 1 << endl;
    }
}