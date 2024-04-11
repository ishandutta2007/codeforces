#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MAXN = 1e5 + 10;
int MOD;

int add(int a, int b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
    return a;
}

int sub(int a, int b) {
    a -= b;
    if (a < 0)
        a += MOD;
    return a;
}

int mul(int a, int b) {
    return (ll) a * b % MOD;
}

int n;
map<int, int> cnt;
int a[MAXN];
int b[MAXN];

void read() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    cin >> MOD;
}

int ans;

void run() {
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
        cnt[b[i]]++;
    }
    int have = 0;
    for (int i = 0; i < n; i++) {
        have += a[i] == b[i];
    }
    ans = 1;
    for (auto i : cnt) {
        int fans = 1;
        for (int x = 1; x <= i.second; x++) {
            int add = x;
            while (add % 2 == 0 && have > 0) {
                add /= 2;
                have--;
            }
            fans = mul(fans, add);
        }
        ans = mul(ans, fans);
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