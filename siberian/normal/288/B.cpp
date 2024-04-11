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

int binpow(int a, int n) {
    int ans = 1;
    while (n) {
        if (n & 1) {
            ans = mul(ans, a);
        }
        a = mul(a, a);
        n >>= 1;
    }
    return ans;
}

int n, k;

void read() {
    cin >> n >> k;
}

int ans;

bool check(vector<int> p) {
    vector<bool> used(p.size(), false);

    for (int i = 0; i < (int)p.size(); i++) {
        if (used[i]) continue;
        int x = i + 1;
        bool flag = false;
        for (int j = 0; j < (int)p.size(); j++) {
            used[x - 1] = true;
            x = p[x - 1];
            if (x == 1) {
                flag = true;
                break;
            }
        }
        if (!flag) return false;
    }
    return true;
}

int calc(vector<int> p, int k) {
    if (p.size() == k) {
        return check(p);
    }
    p.push_back(0);
    int ans = 0;
    for (int i = 1; i <= k; i++) {
        p[p.size() - 1]++;
        ans = add(ans, calc(p, k));
    }
    return ans;
}

int calc(int k) {
    return calc({}, k);
}

vector<int> have = {1,2,9,64,625,7776,117649,2097152};

void run() {
    ans = mul(have[k - 1], binpow(n - k, n - k));
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