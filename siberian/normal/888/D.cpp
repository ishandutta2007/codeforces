#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll

ll cnk(int n, int k) {
    ll ans = 1;
    for (int i = n - k + 1; i <= n; i++) 
        ans = ans * i;
    for (int i = 1; i <= k; i++){
        assert(ans % i == 0);
        ans = ans / i;
    }
    return ans;
}

ll calc(int n) {
    int ans = 0;
    vector<int> p(n);
    iota(all(p), 0);
    do {
        int flag = 1;
        for (int i = 0; i < n; i++) {
            if (p[i] == i) {
                flag = 0;
            }
        }
        ans += flag;
    } while (next_permutation(all(p)));
    return ans;
}

int n, k;

void read() {
    cin >> n >> k;
}

ll ans;

void run() {
    ans = 1;
    for (int i = 2; i <= min(k, n); i++) {
        ans += cnk(n, i) * calc(i);
    }
}

void write() {
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read();
    run();
    write();
    return 0;
}