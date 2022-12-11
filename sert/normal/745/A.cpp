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

void shift(string &s) {
    char c = s[0];
    for (int i = 0; i + 1 < s.length(); i++)
        s[i] = s[i + 1];
    s.back() = c;
}

int main() {
    init();

    string t;
    set <string> s;

    cin >> t;
    int n = t.length();
    for (int i = 0; i < n; i++) {
        shift(t);
        s.insert(t);
    }
    cout << s.size();

    return 0;
}