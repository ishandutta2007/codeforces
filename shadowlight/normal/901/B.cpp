#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 300 * 300;
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
    vector <vector <int> > a(n + 1, vector <int> (n + 1, 0));
    a[0][0] = 1;
    a[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        a[i][0] = a[i - 2][0];
        for (int j = 1; j <= n; j++) {
            a[i][j] = (a[i - 1][j - 1] + a[i - 2][j]) % 2;
        }

    }
    cout << n << "\n";
    for (int i = 0; i <= n; i++) {
        cout << a[n][i] << " ";
    }
    cout << "\n" << n - 1 << "\n";
    for (int i = 0; i < n; i++) {
        cout << a[n - 1][i] << " ";
    }
}