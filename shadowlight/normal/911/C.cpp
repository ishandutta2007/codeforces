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
    vector <int> a(3);
    for (int i = 0; i < 3; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if (a[0] == 1) {
        cout << "YES\n";
        return 0;
    }
    if (a[0] == a[1] && a[1] == a[2] && a[0] == 3) {
        cout << "YES\n";
        return 0;
    }
    if (a[0] == 2 && a[1] == 2) {
        cout << "YES\n";
        return 0;
    }
    if (a[0] == 2 && a[1] == 4 && a[2] == 4) {
        cout << "YES\n";
        return 0;
    }
    cout << "NO\n";
}