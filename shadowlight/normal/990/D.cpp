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
    if (n == 1) {
        cout << "YES\n";
        cout << "0\n";
        return 0;
    }
    if (a != 1 && b != 1) {
        cout << "NO\n";
        return 0;
    }
    if (a == 1 && b == 1) {
        if (n <= 3) {
            cout << "NO\n";
            return 0;
        }
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (abs(i - j) == 1) {
                    cout << 1;
                } else {
                    cout << 0;
                }
            }
            cout << "\n";
        }
        return 0;
    }
    bool fl = 0;
    if (a == 1) {
        swap(a, b);
        fl = 1;
    }
    vector <vector <int> > gr(n, vector <int> (n, 0));
    for (int i = 0; i < n - a; i++) {
        gr[i][i + 1] = 1;
        gr[i + 1][i] = 1;
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                cout << 0;
                continue;
            }
            if (fl) {
                cout << 1 - gr[i][j];
            } else {
                cout << gr[i][j];
            }
        }
        cout << "\n";
    }
}