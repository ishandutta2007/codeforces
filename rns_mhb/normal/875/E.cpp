#include<bits/stdc++.h>
using namespace std;

template <typename T>
struct RMQ {
    vector <vector<T> > v;
    void build(vector <T> &a, int n) {
        v.resize(n+1);
        int d = 32 - __builtin_clz(n);
        for(int i = 1; i <= n; i ++) v[i].resize(d), v[i][0] = a[i];
        for(int j = 1; (1<<j)<= n; j ++)
            for(int i = 1; i+(1<<j)-1<=n; i ++)
                v[i][j] = min(v[i][j-1], v[i+(1<<j-1)][j-1]);
    }
    T query(int l, int r) {
        int d = 31 - __builtin_clz(r - l + 1);
        return min(v[l][d], v[r - (1 << d) + 1][d]);
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n; n += 2;
    vector <int> a(n+1);
    for(int i = 1; i <= n; i ++) cin >> a[i], a[i] *= -1;
    RMQ <int> mx, mn;
    mx.build(a, n);
    for(int i = 1; i <= n; i ++) a[i] *= -1;
    mn.build(a, n);
    auto cost = [&](int l, int r) {
        int L = mn.query(l, r), R = -mx.query(l, r);
        return max(R-a[l], a[l]-L);
    };
    vector <bool> dp(n+1);
    auto calc = [&](int K) {
        int ed = 1;
        for(int i = 1; i <= n; i ++) {
            dp[i] = (i <= ed);
            if(dp[i] == 0) return 0;
            int L = i, R = n;
            while(L < R) {
                int mid = L + R + 1 >> 1;
                if(cost(i, mid) <= K) L = mid;
                else R = mid - 1;
            }
            if(ed < R) ed = R;
        }
        return 1;
    };
    int L = 0, R = 1 << 30;
    while(L < R) {
        int mid = L + R >> 1;
        if(calc(mid)) R = mid;
        else L = mid + 1;
    }
    cout << R << endl;
}