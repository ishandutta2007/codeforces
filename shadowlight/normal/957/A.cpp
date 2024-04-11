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
    int maxk = 0;
    bool can = false;
    if (s[0] == '?' || s.back() == '?') {
        can = true;
    }
    for (int i = 1; i < n; i++) {
        if (s[i] == '?' && s[i - 1] == '?') {
            can = true;
            continue;
        }
        if (i < n - 1 && s[i] == '?' && s[i - 1] == s[i + 1]) {
            can = true;
            continue;
        }
        if (s[i] != '?' && s[i] == s[i - 1]) {
            cout << "No\n";
            return 0;
        }
    }
    cout << (can ? "Yes\n" : "No\n");
}