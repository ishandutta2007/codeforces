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
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 29) {
            cnt++;
        }
    }
    if (cnt > 1) {
        cout << "NO";
        return 0;
    }
    vector <int> days;
    days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 0; i < 12; i++) {
        bool can = true;
        for (int j = 0; j < n; j++) {
            if (!((i + j) % 12 == 1 && a[j] == 29) && days[(i + j) % 12] != a[j]) {
                can = false;
                break;
            }
        }
        if (can) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}