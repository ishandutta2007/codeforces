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
    string s;
    cin >> s;
    int n = s.size();
    s = s + s;
    int maxl = 1, cnt = 1;
    for (int i = 1; i < (int) s.size(); i++) {
        if (s[i] != s[i - 1]) {
            cnt++;
        } else {
            cnt = 1;
        }
        maxl = max(maxl, cnt);
    }
    cout << min(maxl, n);
}