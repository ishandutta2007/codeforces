#include <bits/stdc++.h>
using namespace std;

void init() {
#ifdef FIRE_MIND
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}

typedef long long ll;
typedef long double ld;

const double EPS = 1e-9;
const int INF = (int)1e9 + 41;
const int N = (int)3e5 + 34;

void solve() {
    string s;
    cin >> s;
    int numa = 0;
    int numb = 0;
    int numc = 0;
    bool fail = false;
    if (s[0] != 'a') fail = true;
    if (s.back() != 'c') fail = true;
    for (int i = 0; i < (int)s.length(); i++) {
        if (s[i] == 'a') numa++;
        else if (s[i] == 'b') numb++;
        else if (s[i] == 'c') numc++;
        else fail = true;

        if (i > 0) {
            if (s[i] == 'a' && s[i - 1] != 'a') fail = true;
            if (s[i] == 'b' && s[i - 1] == 'c') fail = true;
            if (s[i] == 'c' && s[i - 1] == 'a') fail = true;
        }
    }
    if (numc != numa && numc != numb) fail = true;
    if (fail) cout << "NO\n";
    else cout << "YES\n";
}

int main() {
    init();
	solve();
	//solve();
	//solve();
    return 0;
}