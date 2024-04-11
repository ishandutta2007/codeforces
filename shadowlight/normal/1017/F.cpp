#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 4e8 + 7;
const double EPS = 1e-8;
const int SQ = sqrt(MAXN);

int n, a, b, c, d;

int f(int x) {
    return a * x * x * x + b * x * x + c * x + d;
}

int res = 0;

void add(int x) {
    int cnt = 0;
    int d = n;
    while (d > 0) {
        cnt += d / x;
        d /= x;
    }
    res += cnt * f(x);
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    cin >> n >> a >> b >> c >> d;
    vector <int> p;
    for (int i = 2; i < SQ; i++) {
        bool can = true;
        for (int x : p) {
            if (i % x == 0) {
                can = false;
                break;
            }
        }
        if (can) {
            p.push_back(i);
        }
    }
    for (int x : p) {
        add(x);
    }
    for (int i = SQ; i <= n; i += SQ) {
        int l = i, r = min(n, i + SQ - 1);
        vector <bool> isp(r - l + 1, true);
        for (int x : p) {
            int d = ((l - 1) / x + 1) * x;
            for (; d <= r; d += x) {
                isp[d - l] = false;
            }
        }
        for (int j = l; j <= r; j++) {
            if (!isp[j - l]) continue;
            add(j);
        }
    }
    cout << (res < 0 ? (ll) res + (1LL << 32) : res);
}