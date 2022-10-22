#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

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
    int n, k, v;
    cin >> n >> k >> v;
    vector <int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum < v) {
        cout << "NO\n";
        return 0;
    }
    int x = (sum - v) % k;
    vector <vector <int> > pred(n + 1, vector <int> (k, -1));
    pred[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        int x = a[i - 1] % k;
        for (int j = 0; j < k; j++) {
            if (pred[i - 1][j] == -1) continue;
            if (pred[i][(j + x) % k] != 0) {
                pred[i][(j + x) % k] = 1;
            }
            pred[i][j] = 0;
        }
    }
    if (pred[n][x] == -1) {
        cout << "NO\n";
        return 0;
    }
    int now = x;
    vector <int> need;
    for (int i = n; i > 0; i--) {
        int kek = pred[i][now];
        if (!kek) {
            need.push_back(i - 1);
        } else {
            now = (now - a[i - 1] % k + k) % k;
        }
    }
    cout << "YES\n";
    vector <int> good(n, 0);
    for (int i : need) {
        good[i] = 1;
    }
    int w1 = -1, w2 = -1;
    int v1 = 0, v2 = 0;
    for (int i = 0; i < (int) good.size(); i++) {
        if (good[i]) {
            if (w1 == -1) {
                w1 = i;
            } else {
                if (a[i]) {
                    cout << (a[i] - 1) / k + 1 << " " << i + 1 << " " << w1 + 1 << "\n";
                }
            }
            v1 += a[i];
        } else {
            if (w2 == -1) {
                w2 = i;
            } else {
                if (a[i]) {
                    cout << (a[i] - 1) / k + 1 << " " << i + 1 << " " << w2 + 1 << "\n";
                }
            }
            v2 += a[i];
        }
    }
    if (w2 == -1) {
        w2 = (w1 ? 0 : 1);
    } else if (w1 == -1) {
        w1 = (w2 ? 0 : 1);
    }
    if (v1 < v) {
        cout << (v - v1) / k << " " << w2 + 1 << " " << w1 + 1;
    } else if (v1 > v) {
        cout << (v1 - v) / k << " " << w1 + 1 << " " << w2 + 1;
    }
}