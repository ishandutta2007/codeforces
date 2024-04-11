#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e5 + 7;
const double EPS = 1e-8;
const int LOGN = 30;

int gcd(int a, int b) {
    if (!a) {
        return b;
    }
    return gcd(b % a, a);
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
    #endif // MY
    int n;
    cin >> n;
    int cnt = 0;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1) {
            cnt++;
        }
    }
    if (cnt) {
        cout << n - cnt;
        return 0;
    }
    int ans = INF;
    int now = 0;
    for (int i = 0; i < n; i++) {
        now = 0;
        for (int j = i; j < n; j++) {
            now = gcd(now, a[j]);
            if (now == 1) {
                ans = min(ans, j - i + 1 + n - 2);
            }
        }
    }
    if (ans == INF) {
        cout << -1;
        return 0;
    }
    cout << ans;
}