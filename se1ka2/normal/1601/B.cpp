#include <functional>
#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> P;

const int INF = 10000000;

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

int a[300005], b[300005];
vector<int> x[300005];
int dp1[300005];
int dp2[300005];
bool d[300005];
int last[300005];

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    for(int i = 1; i <= n; i++) x[i + b[i]].push_back(i);
    SegmentTree<P> seg(n + 1, [](P a, P b){return min(a, b);}, P(INF, INF));
    for(int i = 1; i <= n; i++) seg.set(i, P(i - a[i], i));
    seg.build();
    dp1[0] = dp2[0] = 0;
    for(int i = 1; i <= n; i++) dp1[i] = dp2[i] = INF;
    d[0] = true;
    queue<int> que;
    que.push(0);
    while(que.size()){
        int u = que.front();
        que.pop();
        while(true){
            P p = seg.query(u, n + 1);
            if(p.first > u) break;
            int v = p.second;
            dp1[v] = dp2[u] + 1;
            last[v] = u;
            for(int w : x[v]){
                if(d[w]) continue;
                d[w] = true;
                dp2[w] = dp1[v];
                que.push(w);
            }
            seg.update(p.second, P(INF, INF));
        }
    }
    if(dp1[n] == INF){
        cout << -1 << endl;
        return 0;
    }
    cout << dp1[n] << endl;
    int u = n;
    while(u != 0){
        u = last[u];
        cout << u << " ";
        u += b[u];
    }
    cout << endl;
}