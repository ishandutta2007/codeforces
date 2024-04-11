#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ != 4 && __GNUC_MINOR__ != 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;

const int N = (int)1e6 + 34;
const ll INF = 1e9 + 34;

int main() {
    //init();
    //freopen("a.in", "r", stdin);
    int n, x;
    string s;
    int h = 0;

    cin >> n;
    while (n--) {
        cin >> x >> s;
        if ((h == 0 && s != "South") || (h == 20000 && s != "North")) {
            cout << "NO";
            return 0;
        }
        if (s == "South") h += x;
        if (s == "North") h -= x;
        if (h < 0 || h > 20000) {
            cout << "NO";
            return 0;
        }
    }
    if (h == 0)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}