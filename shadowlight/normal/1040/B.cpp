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
    int n, k;
    cin >> n >> k;
    int d = n % (2 * k + 1);
    vector <int> res;
    if (!d) {
        for (int i = k + 1; i <= n; i += 2 * k + 1) {
            res.push_back(i);
        }
    } else if (d >= k + 1) {
        res.push_back(d - k);
        for (int i = d + k + 1; i <= n; i += 2 * k + 1) {
            res.push_back(i);
        }
    } else {
        for (int i = 1; i <= n; i += 2 * k + 1) {
            res.push_back(i);
        }
    }
    cout << res.size() << "\n";
    for (int x : res) {
        cout << x << " ";
    }
}