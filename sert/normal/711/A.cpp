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

int n, a, b, m, c;
string s[N];
bool fnd;

int main() {
    //init();
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        if (s[i][0] == 'O' && s[i][1] == 'O' && !fnd) {
            s[i][0] = s[i][1] = '+';
            fnd = true;
        }
        if (s[i][3] == 'O' && s[i][4] == 'O' && !fnd) {
            s[i][3] = s[i][4] = '+';
            fnd = true;
        }
    }

    if (fnd) {
        cout << "YES\n";
        for (int i = 0; i < n; i++)
            cout << s[i] << "\n";
    } else {
        cout << "NO\n";
    }


    return 0;
}