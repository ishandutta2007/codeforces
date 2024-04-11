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
    int n, a, b;
    cin >> n >> a >> b;
    int sum = 0;
    vector <int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    for (int i = 0; i < n / 2; i++) {
        if (t[i] != 2 && t[n - i - 1] != 2) {
            if (t[i] != t[n - i - 1]) {
                cout << -1;
                return 0;
            }
        } else if (t[i] == 2 && t[n - i - 1] == 2) {
            sum += min(2 * a, 2 * b);
        } else if (t[i] != 2) {
            sum += (t[i] ? b : a);
        } else {
            sum += (t[n - i - 1] ? b : a);
        }
    }
    if (n % 2 && t[n / 2] == 2) {
        sum += min(a, b);
    }
    cout << sum;
}