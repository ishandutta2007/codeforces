#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define TASKNAME ""

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
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
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool can = true;
        for (int j = 0; j < n / 2; j++) {
            int k = abs(s[j] - s[n - 1 - j]);
            if (k && k != 2) {
                can = false;
                break;
            }
        }
        cout << (can ? "YES\n" : "NO\n");
    }
}