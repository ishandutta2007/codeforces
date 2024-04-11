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
    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    bool can = false;
    for (int i = p; i < n; i++) {
        if (s[i - p] != s[i]) {
            if (s[i] == '.') {
                s[i] = '0' + '1' - s[i - p];
            } else if (s[i - p] == '.') {
                s[i - p] = '0' + '1' - s[i];
            }
            can = true;
            break;
        } else if (s[i] == '.') {
            s[i] = '1';
            s[i - p] = '0';
            can = true;
            break;
        }
    }
    if (!can) {
        cout << "No\n";
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == '.') {
            cout << 0;
        } else {
            cout << s[i];
        }
    }
}