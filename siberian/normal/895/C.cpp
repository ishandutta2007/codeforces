#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MOD = 1e9 + 7;

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

const int MAXN = 1e5 + 10; 
int pows[MAXN];

void build() {
    pows[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        pows[i] = mul(pows[i - 1], 2);
    }
}

const int MAXA = 71;
int n;
int cnt[MAXA];

void read() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
}

int lp[MAXA];
vector<int> p;
int masks[MAXA];

void gen_masks() {
    for (int i = 2; i < MAXA; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            p.push_back(i);
        }
        for (int j = 0; j < (int)p.size() && p[j] * i < MAXA && p[j] <= lp[i]; j++) {
            lp[i * p[j]] = p[j];
        }
    }
    for (int i = 1; i < MAXA; i++) {
        masks[i] = 0;
        for (int j = 0; j < (int)p.size() && p[j] <= i; j++) {
            int x = i;
            while (x % p[j] == 0) {
                masks[i] ^= (1 << j);
                x /= p[j];
            }
        }
    }
}


const int MAXBIT = 19;
int ans;
int dp[1 << MAXBIT][2];

void calc() {
    dp[0][0] = 1;
    for (int x = 1; x < MAXA; x++) {
        if (!cnt[x]) continue;
        for (int mask = 0; mask < (1 << MAXBIT); mask++) {
            dp[mask][1] = add(dp[mask][1], mul(dp[mask ^ masks[x]][0], pows[cnt[x] - 1]));
            dp[mask][1] = add(dp[mask][1], mul(dp[mask][0], pows[cnt[x] - 1]));
        }
        for (int mask = 0; mask < (1 << MAXBIT); mask++) {
            swap(dp[mask][0], dp[mask][1]);
            dp[mask][1] = 0;
        }
    }
    ans = sub(dp[0][0], 1);
}

void run() {
    gen_masks();
    calc();
}

void write() {
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    build();
    read();
    run();
    write();
    return 0;
}