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

string delshit(string s) {
    string ans;
    for (char ch: s) {
        if ('a' <= ch && ch <= 'z')
            ans.push_back(ch);
        if ('A' <= ch && ch <= 'Z')
            ans.push_back(ch - 'A' + 'a');
    }
    return ans;
}

int n, m;
string s[N];
int ans = 1;
bool ok;

int main() {
    init();

    cin >> n >> m;
    for (int i = 0; i < n; cin >> s[i++]);

    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
    for (int h = 1; h + i <= n; h++)
    for (int w = 1; w + j <= m; w++) {
        ok = true;
        for (int ii = i; ii < i + h; ii++)
            for (int jj = j; jj < j + w; jj++)
                if (s[ii][jj] == '1')
                    ok = false;
        if (ok)
            ans = max(ans, h * 2 + w * 2);
    }

    cout << ans;

    return 0;
}