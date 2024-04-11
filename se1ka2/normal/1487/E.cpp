#include <functional>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1000000000;

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

int a[4][150005];
vector<int> v[4][150005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n[4];
    for(int i = 0; i < 4; i++) cin >> n[i];
    int m = max({n[0], n[1], n[2], n[3]});
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < n[i]; j++) cin >> a[i][j];
    }
    for(int i = 1; i < 4; i++){
        int m;
        cin >> m;
        for(int j = 0; j < m; j++){
            int x, y;
            cin >> x >> y;
            x--; y--;
            v[i][y].push_back(x);
        }
        for(int j = 0; j < n[i]; j++){
            v[i][j].push_back(-1);
            v[i][j].push_back(n[i - 1]);
        }
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < m; j++) sort(v[i][j].begin(), v[i][j].end());
    }
    vector<SegmentTree<int>> seg(4, SegmentTree<int>(m, [](int a, int b){return min(a, b);}, INF));
    for(int j = 0; j < n[0]; j++) seg[0].set(j, a[0][j]);
    seg[0].build();
    for(int i = 1; i < 4; i++){
        for(int j = 0; j < n[i]; j++){
            for(int k = 0; k < (int)v[i][j].size() - 1; k++){
                seg[i].set(j, min(seg[i][j], seg[i - 1].query(v[i][j][k] + 1, v[i][j][k + 1]) + a[i][j]));
            }
        }
        seg[i].build();
    }
    int ans = seg[3].query(0, n[3]);
    if(ans > INF / 2) cout << -1 << "\n";
    else cout << seg[3].query(0, n[3]) << "\n";
}