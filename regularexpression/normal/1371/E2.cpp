#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define len(a) ((int) (a).size())
#define all(a) (a).begin(), (a).end()

#define div asasdas

const int N = 228228, INF = 1e9 + 228;

int p;

int add(int a, int b) {
    return a + b >= p ? a + b - p : a + b;
}

int sub(int a, int b) {
    return a - b < 0 ? a - b + p : a - b;
}

int mult(int a, int b) {
    return (ll) a * b % p;
}

int binPow(int a, int n) {
    int res = 1;
    while (n > 0) {
        if (n & 1) res = mult(res, a);
        a = mult(a, a);
        n >>= 1;
    }
    return res;
}

int fact[N], invFact[N];

int cnk(int n, int k) {
    if (n < 0 || k < 0 || n < k) return 0;
    return mult(fact[n], mult(invFact[k], invFact[n - k]));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n >> p;
    fact[0] = 1;
    for (int i = 1; i < N; i++) fact[i] = mult(fact[i - 1], i);
    for (int i = 0; i < N; i++) invFact[i] = binPow(fact[i], p - 2);
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int l = -1, r = INF;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        vector<int> cnt(n, 0);
        bool ok = 1;
        for (int i = 0; i < n; i++) {
            int where = max(0, a[i] - mid);
            if (where >= n) {
                ok = 0;
                break;
            }
            cnt[where]++;
        }
        int sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            sum += cnt[i];
            if (sum > n - i) {
                ok = 0;
                break;
            }
        }
        (ok ? r : l) = mid;
    }
    int xL = r;
    l = xL - 1, r = INF;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        vector<int> cnt(n, 0);
        for (int i = 0; i < n; i++) {
            int where = max(0, a[i] - mid);
            cnt[where]++;
        }
        int now = 0, ways = 1;
        for (int i = n - 1; i >= 0; i--) {
            ways = mult(ways, mult(fact[cnt[i]], cnk(n - i - now, cnt[i])));
            now += cnt[i];
        }
        (ways == 0 ? r : l) = mid;
    }
    int xR = l;
    cout << xR - xL + 1 << '\n';
    for (int x = xL; x <= xR; x++) cout << x << " ";
    return 0;
}