#include <bits/stdc++.h>
#define ll long long
#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-6;

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
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (s.size() == 1 || (s.size() == 2 && s[0] >= s[1])) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        cout << "2\n";
        cout << s[0] << " " << s.substr(1, s.size()) << "\n";
    }
}