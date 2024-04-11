#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MOD = 998244353;

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
vector<int> a;

void read() {
    cin >> n;
    a.resize(n);
    for (auto &i : a) {
        cin >> i;
    }
}

const int MAXLEN = 11;
int cnt[MAXLEN];

int get_len(int x) {
    int ans = 0;
    while (x) {
        ans++;
        x /= 10;
    }
    return ans;
}

int calcL(int x, int lenY) {
    int ans = 0;
    int pow = 1;
    while (x || lenY) {
        if (x && lenY) {
            pow = mul(pow, 10);
            ans = add(ans, mul(pow, x % 10));
            x /= 10;
            pow = mul(pow, 10);
            lenY--;
        } else if (x) {
            ans = add(ans, mul(pow, x % 10));
            x /= 10;
            pow = mul(pow, 10);
        } else {
            break;
        }
    }
    return ans;
}

int calcR(int y, int lenX) {
    int ans = 0;
    int pow = 1;
    while (y || lenX) {
        if (y && lenX) {
            ans = add(ans, mul(pow, y % 10));
            pow = mul(pow, 10);
            y /= 10;
            pow = mul(pow, 10);
            lenX--;
        } else if (y) {
            ans = add(ans, mul(pow, y % 10));
            y /= 10;
            pow = mul(pow, 10);
        } else {
            break;
        }
    }
    return ans;
}

int ans;

void run() {
    for (auto i : a) {
        cnt[get_len(i)]++;
    }
    ans = 0;
    for (int i = 0; i < n; i++) {
        for (int lenY = 1; lenY < MAXLEN; lenY++) {
            ans = add(ans, mul(cnt[lenY], calcL(a[i], lenY)));
        }
        for (int lenX = 1; lenX < MAXLEN; lenX++) {
            ans = add(ans, mul(cnt[lenX], calcR(a[i], lenX)));
        }
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