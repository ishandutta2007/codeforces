#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;
const int N = (int)1e6 + 34;

int a[N];
int main() {
    init();
    int n, h;
    string s;
    cin >> n >> s;
    if (n == 12) n++;
    if (s[3] > '5') s[3] = '1';
    h = (s[0] - '0') * 10 + s[1] - '0';
    if (h >= n) s[0] = (s[1] == '0' ? '1' : '0');
    if (h == 0 && n == 13) s[1] = '2';
    cout << s;

    return 0;
}