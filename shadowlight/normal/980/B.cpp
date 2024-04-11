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
    vector <vector <int> > a(4, vector <int> (n, 0));
    if (k % 2) {
        k--;
        a[1][n / 2] = 1;
    }
    if (k == 2 * (n - 2)) {
        for (int i = 1; i <= 2; i++) {
            for (int j = 1; j < n - 1; j++) {
                a[i][j] = 1;
            }
        }
    }
    for (int i = 1; i <= min(k / 2, (n - 3) / 2); i++) {
        a[1][i] = 1;
        a[1][n - i - 1] = 1;
    }
    k -= n - 3;
    for (int i = 1; i <= min(k / 2, (n - 3) / 2); i++) {
        a[2][i] = 1;
        a[2][n - i - 1] = 1;
    }
    cout << "YES\n";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < n; j++) {
            cout << (a[i][j] ? "#" : ".");
        }
        cout << endl;
    }
}