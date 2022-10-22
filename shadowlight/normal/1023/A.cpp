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
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    int pos = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '*') {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        cout << (s == t ? "YES\n" : "NO\n");
        return 0;
    }
    int len1 = pos;
    int len2 = s.size() - pos - 1;
    //cout << len1 << " " << len2 << "\n";
    if (s.size() - 1 <= t.size() && s.substr(0, len1) == t.substr(0, len1) && s.substr(s.size() - len2, len2) == t.substr(t.size() - len2, len2)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}