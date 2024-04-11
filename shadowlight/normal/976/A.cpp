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
    string s;
    cin >> s;
    if (n == 1 && s == "0") {
        cout << 0;
        return 0;
    }
    int cnt = 0;
    for (char c : s) {
        if (c == '0') {
            cnt++;
        }
    }
    cout << '1';
    for (int i = 0; i < cnt; i++) {
        cout << '0';
    }
}