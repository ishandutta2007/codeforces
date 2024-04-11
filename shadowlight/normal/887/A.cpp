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
    ll cnt = 0;
    string s;
    cin >> s;
    bool fl = 0;
    for (char c : s) {
        if (c == '1') {
            fl = 1;
        } else if (fl) {
            cnt++;
        }
    }
    if (cnt >= 6) {
        cout << "yes\n";
    } else {
        cout << "no\n";
    }
}