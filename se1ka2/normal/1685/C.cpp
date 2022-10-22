#include <functional>
#include <iostream>
#include <vector>
using namespace std;

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

vector<int> v[200005];

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        string s;
        cin >> n >> s;
        n *= 2;
        for(int i = 0; i <= n; i++)
        {
            v[i].clear();
        }
        int h[200005];
        h[0] = 0;
        v[h[0]].push_back(0);
        SegmentTree<int> seg(n + 1, [](int a, int b){return max(a, b);}, -INF);
        seg.set(0, h[0]);
        for(int i = 1; i <= n; i++)
        {
            if(s[i - 1] == '(')
            {
                h[i] = h[i - 1] + 1;
            }
            else
            {
                h[i] = h[i - 1] - 1;
            }
            if(h[i] >= 0)
            {
                v[h[i]].push_back(i);
            }
            seg.set(i, h[i]);
        }
        seg.build();
        int dp[200005];
        int last[200005];
        dp[0] = 0;
        last[0] = -1;
        for(int i = 1; i <= n; i++)
        {
            dp[i] = dp[i - 1];
            last[i] = -1;
            if(h[i] < 0)
            {
                dp[i]++;
            }
            else
            {
                int k = seg.query(0, i + 1);
                int l = *lower_bound(v[k - h[i]].begin(), v[k - h[i]].end(), 0);
                if(dp[l] + 1 <= dp[i])
                {
                    dp[i] = dp[l] + 1;
                    last[i] = l;
                }
            }
        }
        cout << dp[n] << endl;
        int i = n;
        while(i)
        {
            if(last[i] != -1)
            {
                cout << last[i] + 1 << " " << i << endl;
                i = last[i];
            }
            else
            {
                i--;
            }
        }
    }
}