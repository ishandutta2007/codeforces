#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e5 + 7;
const double EPS = 1e-8;
const int LOGN = 30;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
    #endif // MY
    int n, x;
    cin >> n >> x;
    int res = n - 1;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        res += t;
    }
    if (res == x) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}