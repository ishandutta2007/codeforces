#include <bits/stdc++.h>
using namespace std;

void init() {
//#if __GLIBCXX__ == 20160609
#ifdef FIRE_MIND
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#else
    ///freopen(TASKNAME".in", "r", stdin);
    ///freopen(TASKNAME".out", "w", stdout);
#endif
}
#define pb push_back
#define fi first
#define se second

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const double EPS = 1e-9;
const int INF = (int)1e9 + 41;
const int N = (int)1e6 + 34;

int main() {
    init();
    string s;
    int n;
    bool f = false;
    bool d = false;

    cin >> s >> n;
    string t;

    for (int i = 0; i < n; i++) {
        cin >> t;
        if (s == t) {
            cout << "YES\n";
            return 0;
        }
        if (t[0] == s[1]) d = true;
        if (t[1] == s[0]) f = true;
    }

    if (d && f)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}