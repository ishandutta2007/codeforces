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
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int n;
        cin >> n;
        if (n % 4 == 0) {
            cout << n / 4;
        } else if (n % 4 == 1) {
            if (n < 9) {
                cout << -1;
            } else {
                cout << (n - 9) / 4 + 1;
            }
        } else if (n % 4 == 2) {
            if (n < 6) {
                cout << -1;
            } else {
                cout << (n - 6) / 4 + 1;
            }
        } else {
            if (n < 15) {
                cout << -1;
            } else {
                cout << (n - 15) / 4 + 2;
            }
        }
        cout << "\n";
    }
}