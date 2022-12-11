#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;
const int INF = 1e9;

bool ok[N];
char c[N];
set <pair<char, char> > ans;

bool fail() {
    cout << "-1\n";
    exit(0);
}

int main() {
    init();

    string s, k;
    cin >> s >> k;
    int n = s.length();

    for (int i = 0; i < n; i++) {
        if (s[i] == k[i]) {
            ok[s[i] - 'a'] = true;
            continue;
        }
        if (c[s[i] - 'a'] && c[s[i] - 'a'] != k[i])
            fail();
        if (c[k[i] - 'a'] && c[k[i] - 'a'] != s[i])
            fail();
        c[s[i] - 'a'] = k[i];
        c[k[i] - 'a'] = s[i];
        ans.insert({min(s[i], k[i]), max(s[i], k[i])});
    }

    for (int i = 0; i < 26; i++) {
        if (ok[i] && c[i])
            fail();
    }

    cout << ans.size() << "\n";
    for (auto q: ans) {
        cout << q.first << " " << q.second << "\n";
    }

    return 0;
}