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

ostream& operator << (ostream &fo, vector<int> v) {
    for (int i = 0; i < (int)v.size(); i++)
        fo << v[i] << " ";
    return fo;
}

typedef long long ll;
const int INF = (int)1e9 + 34;
const int N = 4004;

bool ok(char a, char b) {
    if ('a' <= a && a <= 'z') a += 'A' - 'a';
    if ('a' <= b && b <= 'z') b += 'A' - 'a';
    if (a == b) return true;
    if (a == 'O' && b == '0') return true;
    if (a == '0' && b == 'O') return true;
    if ((a == '1' || a == 'L' || a == 'I') && (b == '1' || b == 'L' || b == 'I')) return true;
    return false;
}

bool ok(string a, string b) {
    if (a.length() != b.length()) return false;
    for (int i = 0; i < (int)a.length(); i++) {
        if (!ok(a[i], b[i])) return false;
    }
    return true;
}

void solve() {
    string s, t;
    int n;
    cin >> s;
    cin >> n;
    bool qq = false;
    while (n--) {
        cin >> t;
        if (ok(s, t)) {
            qq = true;
        }
    }
    if (qq) cout << "No\n";
    else cout << "Yes\n";
}

int main() {
    init();

    int it = 1;
#ifdef FIRE_MIND
    it = 6;
#endif

    for (int i = 0; i < it; i++) {
        solve();
    }

    return 0;
}