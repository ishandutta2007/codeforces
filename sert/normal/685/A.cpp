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

string it7(int x, int len) {
    string res = "";
    for (int i = 0; i < len; i++) {
        res.push_back(char('0' + x % 7));
        x /= 7;
    }
    return res;
}

int check(string s) {
    sort(s.begin(), s.end());
    for (int i = 1; i < (int)s.length(); i++)
        if (s[i] == s[i - 1])
            return 0;
    return 1;
}

int main() {
    init();
    int n, m;
    cin >> n >> m;

    int b1 = (1.000001 + log(max(1, n - 1)) / log(7));
    int b2 = (1.000001 + log(max(1, m - 1)) / log(7));

    if (b1 + b2 > 7) {
        cout << 0;
        return 0;
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            ans += check(it7(i, b1) + it7(j, b2));
    cout << ans;

    return 0;
}