#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define mp(x, y) make_pair(x, y)
#define fst first
#define snd second

using namespace std;

using vi = vector<int>;
using ll = long long;
using pii = pair<int, int>;

#define FNAME "a"

#ifdef LOCAL
#define eprintf(args...) fprintf(stderr, args), fflush(stderr)
#else
#define eprintf(args...) ;
#endif

int n;
string unify(string s) {
    for (auto &c: s) {
        if (isupper(c)) {
            c += ('a' - 'A');
        }
        if (c == 'o') {
            c = '0';
        }
        if (c == 'i' || c == 'l') {
            c = '1';
        }
    }
    return s;
}

string user;
set<string> lib;

bool read() {
    if (!(cin >> user)) {
        return 0;
    }
    user = unify(user);

    int n;
    cin >> n;

    lib.clear();
    forn(i, n) {
        string s;
        cin >> s;
        s = unify(s);
        lib.insert(s);
    }
    return 1;
}

bool solve() {
    return lib.count(user) == 0;
}

int main() {
#ifdef LOCAL
    freopen(FNAME ".in", "r", stdin);
    freopen(FNAME ".out", "w", stdout);
#endif

    while (read()) {
        cout << (solve() ? "Yes" : "No") << '\n';
    }

    return 0;
}