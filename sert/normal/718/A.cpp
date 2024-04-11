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

const int N = (int)1e6 + 34;

int main() {
    init();
    int n, t;
    string s;
    cin >> n >> t >> s;
    int p = 0;
    while (s[p] != '.') p++;
    p++;
    while (p < n && s[p] < '5') p++;

    if (p == n) {
        cout << s;
        return 0;
    }


    while (p + 1 < n) {
        n--;
        s.pop_back();
    }

    while (true) {
        if (s[p - 1] == '.') break;
        if (t == 0) break;
        if (s[p] < '5') break;

        s[p - 1]++;
        p--;
        t--;
        s.pop_back();
    }

    if (s.back() >= '5' && s[p - 1] == '.' && t > 0) {
        s.pop_back();
        s.pop_back();
        p = s.length() - 1;
        while (p >= 0 && s[p] == '9') {
            s[p] = '0';
            p--;
        }
        if (p < 0)
            s = "1" + s;
        else
            s[p]++;
    }

    cout << s;


    return 0;
}