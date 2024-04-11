#include <bits/stdc++.h>
#define ll long long
#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-6;

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
   int n;
   cin >> n;
   vector <int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    map <pair <int, int>, int> cnt;
    int add = 0;
    for (int i = 0; i < n; i++) {
        int g = __gcd(abs(a[i]), abs(b[i]));
        if (!a[i]) {
            if (!b[i]) {
                add++;
            }
            continue;
        }
        if (a[i] < 0) {
            a[i] *= -1, b[i] *= -1;
        }
        cnt[{-b[i] / g, a[i] / g}]++;
    }
    int res = 0;
    for (auto t : cnt) {
        res = max(res, t.second);
    }
    cout << res + add;
}