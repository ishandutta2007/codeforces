#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 2e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;
const int SQ = sqrt(INF);

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
    vector <int> pr;
    vector <int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    int x = a[0], y = b[0];
    for (int i = 2; i <= SQ; i++) {
        if (x % i && y % i) continue;
        pr.push_back(i);
        while (x % i == 0) {
            x /= i;
        }
        while (y % i == 0) {
            y /= i;
        }
    }
    if (x != 1) {
        pr.push_back(x);
    }
    if (y != 1) {
        pr.push_back(y);
    }
    for (int p : pr) {
        bool can = true;
        for (int i = 0; i < n; i++) {
            if (a[i] % p && b[i] % p) {
                can = false;
                break;
            }
        }
        if (can) {
            cout << p;
            return 0;
        }
    }
    cout << -1;
}