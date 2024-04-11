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
    if (n < 6) {
        cout << "-1\n";
    } else {
        cout << "1 2\n";
        cout << "2 3\n";
        cout << "2 4\n";
        for (int i = 5; i <= n; i++) {
            cout << "1 " << i << "\n";
        }
    }
    for (int i = 0; i < n - 1; i++) {
        cout << i + 1 << " " << i + 2 << "\n";
    }
}