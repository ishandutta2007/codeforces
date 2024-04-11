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
const ll INF = 1e12;

void check(char a, char b, char c) {
    if (a == 'x' && b == 'x' && c == '.') {
        cout << "YES";
        exit(0);
    }
    if (a == '.' && b == 'x' && c == 'x') {
        cout << "YES";
        exit(0);
    }
    if (a == 'x' && b == '.' && c == 'x') {
        cout << "YES";
        exit(0);
    }
}

int main() {
    init();
    string s[4];
    for (int i = 0; i < 4; i++)
        cin >> s[i];

    for (int i = 0; i < 4; i++)
    for (int j = 0; j < 2; j++) {
        check(s[i][j], s[i][j + 1], s[i][j + 2]);
        check(s[j][i], s[j + 1][i], s[j + 2][i]);
    }

    for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) {
        check(s[i][j], s[i + 1][j + 1], s[i + 2][j + 2]);
        check(s[3 - i][j], s[2 - i][j + 1], s[1 - i][j + 2]);
    }

    cout << "NO";

    return 0;
}