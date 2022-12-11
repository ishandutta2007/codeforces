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
const int N = 63e5 + 34;
const ll INF = 2e9 + 34;
int MD = 30;

string sym = "AHIMOTUVWXYovwx";
void fail() {
    cout << "NIE";
    exit(0);
}

int main() {
    init();
    string s;
    cin >> s;
    int n = s.length();
    if (n % 2 && sym.find(s[n / 2]) > 3000) fail();
    for (int i = 0; i < n / 2; i++) {
        if (sym.find(s[i]) < 3000 && sym.find(s[n - i - 1]) < 300 && s[i] == s[n - i - 1]) continue;
        if (s[i] == 'b' && s[n - i - 1] == 'd') continue;
        if (s[i] == 'd' && s[n - i - 1] == 'b') continue;
        if (s[i] == 'p' && s[n - i - 1] == 'q') continue;
        if (s[i] == 'q' && s[n - i - 1] == 'p') continue;
        fail();
    }
    cout << "TAK";
    return 0;
}