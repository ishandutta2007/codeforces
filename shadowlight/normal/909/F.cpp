#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;
const int LOGN = 30;

vector <int> res;

bool solve1(int n) {
    if (n == 1) {
        return false;
    }
    if (!n) {
        return true;
    }
    int x = 1;
    while (x <= n) {
        x *= 2;
    }
    x--;
    for (int k = n; ; k--) {
        int l = x - k;
        if (!l) {
            return false;
        }
        if (l >= k) {
            break;
        }
        swap(res[k], res[l]);
    }
    solve1(x - n - 1);
}

void solve2(int n) {
    if (n < 6) {
        cout << "NO\n";
        return;
    }
    int k = n;
    while (k % 2 == 0) {
        k /= 2;
    }
    if (k == 1) {
        cout << "NO\n";
        return;
    }
    vector <bool> used(n + 1, 0);
    vector <int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = i;
    }
    swap(a[1], a[5]);
    used[1] = 1;
    used[5] = 1;
    for (int bit = LOGN; bit > 0; bit--) {
        if ((1 << bit) > n) continue;
        vector <int> b;
        for (int i = 1; i <= n; i++) {
            if (((i >> bit) & 1) == 0 || used[i]) continue;
            if (!used[i]) {
                b.push_back(i);
                used[i] = 1;
            }
        }
        int x = b.back();
        for (int i = 1; i < (int) b.size(); i++) {
            a[b[i]] = b[i - 1];
        }
        a[b[0]] = x;
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
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
    int n;
    cin >> n;
    res.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        res[i] = i;
    }
    if (!solve1(n)) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (int i = 1; i <= n; i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
    solve2(n);
}