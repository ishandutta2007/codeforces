#include <functional>
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> P;

struct LazySegmentTree
{
    int n;
    vector<P> seg;
    vector<int> lazy;
    
    LazySegmentTree(int nn){
        n = 1;
        while(n < nn) n <<= 1;
        seg.assign(n * 2, P(0, 1));
        lazy.assign(n * 2, -1);
    }
    
    void set(int i, int x){
        seg[i + n] = P(x, 1);
    }
    
    void build(){
        for(int k = n - 1; k > 0; k--){
            seg[k] = P(seg[k * 2].first + seg[k * 2 + 1].first, seg[k * 2].second + seg[k * 2 + 1].second);
        }
    }
    
    void eval(int k){
        if(lazy[k] != -1){
            seg[k] = P(lazy[k] * seg[k].second, seg[k].second);
            if(k < n){
                lazy[k * 2] = lazy[k];
                lazy[k * 2 + 1] = lazy[k];
            }
            lazy[k] = -1;
        }
    }
    
    void update(int l, int r, int a, int b, int k, int x){
        if(l >= b || r <= a){
            return;
        }
        eval(k);
        if(l <= a && r >= b){
            lazy[k] = x;
            eval(k);
        }
        else{
            update(l, r, a, (a + b) / 2, k * 2, x);
            update(l, r, (a + b) / 2, b, k * 2 + 1, x);
            seg[k] = P(seg[k * 2].first + seg[k * 2 + 1].first, seg[k * 2].second + seg[k * 2 + 1].second);
        }
    }
    
    void update(int l, int r, int x){
        return update(l, r, 0, n, 1, x);
    }
    
    int query(int l, int r, int a, int b, int k){
        eval(k);
        if(l >= b || r <= a){
            return 0;
        }
        if(l <= a && r >= b){
            return seg[k].first;
        }
        return query(l, r, a, (a + b) / 2, k * 2) + query(l, r, (a + b) / 2, b, k * 2 + 1);
    }
    
    int query(int l, int r){
        return query(l, r, 0, n, 1);
    }
    
    int operator[](const int i){
        return query(i, i + 1);
    }
};

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        string s, t;
        cin >> s >> t;
        LazySegmentTree seg(n);
        for(int i = 0; i < n; i++){
            seg.set(i, t[i] - '0');
        }
        seg.build();
        int l[200005], r[200005];
        for(int i = 0; i < q; i++){
            cin >> l[i] >> r[i];
            l[i]--;
        }
        bool f = true;
        for(int i = q - 1; i >= 0; i--){
            int x = seg.query(l[i], r[i]);
            if(x * 2 == r[i] - l[i]){
                f = false;
                break;
            }
            if(x * 2 < r[i] - l[i]) seg.update(l[i], r[i], 0);
            else seg.update(l[i], r[i], 1);
        }
        for(int i = 0; i < n; i++){
            if(s[i] - '0' != seg[i]){
                f = false;
                break;
            }
        }
        if(f) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}