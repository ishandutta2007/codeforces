#include <functional>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1000000009;

template <typename T>
struct SparseTable
{
    using F = function<T(T, T)>;
    
    int n;
    int l;
    vector<vector<T>> dat;
    vector<int> d;
    
    const F f;
    const T e;
    
    SparseTable(int n, const F f, const T e) : n(n), f(f), e(e){
        dat.resize(n);
        d.resize(n + 1);
        int j = 0;
        for(l = 0; l <= n; l++){
            while(j <= n && j < (1 << l)){
                d[j] = l;
                j++;
            }
            if((1 << l) > n){
                for(int i = 0; i < n; i++){
                    dat[i].resize(l);
                }
                break;
            }
        }
    }
    
    void set(int i, T x){
        dat[i][0] = x;
    }
    
    void build(){
        for(int j = 1; j < l; j++){
            for(int i = 0; i <= n - (1 << j); i++){
                dat[i][j] = f(dat[i][j - 1], dat[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    
    T query(int l, int r){
        if(r <= l) return e;
        return f(dat[l][d[r - l] - 1], dat[r - (1 << (d[r - l] - 1))][d[r - l] - 1]);
    }
};

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[200005];
        SparseTable<int> st1(n, [](int a, int b){return max(a, b);}, 0);
        SparseTable<int> st2(n, [](int a, int b){return min(a, b);}, INF);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            st1.set(i, a[i]);
            st2.set(i, a[i]);
        }
        st1.build();
        st2.build();
        bool f = false;
        for(int i = 1; i <= n; i++){
            int k = st1.query(0, i);
            int right = n, left = i;
            while(right - left > 1){
                int mid = (right + left) / 2;
                if(st2.query(i, mid) >= k) left = mid;
                else right = mid;
            }
            if(left == i || st2.query(i, left) > k) continue;
            if(st2.query(i, left - 1) == k && st1.query(left - 1, n) == k){
                cout << "YES" << endl;
                cout << i << " " << (left - 1) - i << " " << n - (left - 1) << endl;
                f = true;
                break;
            }
            if(st1.query(left, n) == k){
                cout << "YES" << endl;
                cout << i << " " << left - i << " " << n - left << endl;
                f = true;
                break;
            }
        }
        if(!f) cout << "NO" << endl;
    }
}