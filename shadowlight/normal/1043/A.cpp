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
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int k = 1; k < 1000; k++) {
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; i++) {
            if (k < a[i]) {
                sum1 = 0;
                sum2 = INF;
                break;
            }
            sum1 += k - a[i];
            sum2 += a[i];
        }
        if (sum1 > sum2) {
            cout << k;
            return 0;
        }
    }
    assert(false);
}