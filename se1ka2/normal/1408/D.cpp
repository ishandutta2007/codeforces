#include <functional>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> P;

const int INF = 100000000;

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

vector<P> v[1000005];

int main()
{
    int n, m;
    cin >> n >> m;
    P p[2005], q[2005];
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        p[i] = P(a, b);
    }
    for(int i = 0; i < m; i++){
        int c, d;
        cin >> c >> d;
        q[i] = P(c, d);
    }
    sort(p, p + n);
    int k = 1;
    for(int i = 1; i < n; i++){
        if(p[i].second < p[i - 1].second){
            p[k] = p[i];
            k++;
        }
    }
    sort(q, q + m, greater<P>());
    int l = 1;
    for(int i = 1; i < m; i++){
        if(q[i].second > q[i - 1].second){
            q[l] = q[i];
            l++;
        }
    }
    reverse(q, q + l);
    for(int i = 0; i < k; i++){
        for(int j = 0; j < l; j++){
            if(p[i].first < q[j].first){
                if(p[i].second >= q[j].second){
                    continue;
                }
                else if(j == l - 1 || p[i].second >= q[j + 1].second){
                    v[0].push_back(P(i, q[j].first - p[i].first));
                    if(j == 0 || p[i].first >= q[j - 1].first){
                        v[q[j].second - p[i].second].push_back(P(i, 0));
                    }
                }
                else{
                    v[q[j + 1].second - p[i].second].push_back(P(i, q[j].first - p[i].first));
                    if(j == 0 || p[i].first >= q[j - 1].first){
                        v[q[j].second - p[i].second].push_back(P(i, 0));
                    }
                }
            }
        }
    }
    SegmentTree<int> seg(n, [](int a, int b){return max(a, b);}, 0ll);
    int ans = INF;
    for(int i = 0; i <= 1000000; i++){
        for(P t : v[i]){
            seg.update(t.first, t.second);
        }
        ans = min(ans, seg.query(0, n) + i);
    }
    cout << ans << endl;
}