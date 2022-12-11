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
const int INF = (ll)1e9 + 34;
const ll md = (ll)1e9 + 7;

int a[N];

int main() {
    init();

    string s;
    cin >> s;
    for (int i = 0; i < (int)s.length(); i++) {
        a[s[i]]++;
    }

    int b = min(min(a['B'], a['u'] / 2), min(a['l'], a['b']));
    int c = min(a['r'] ,min(a['a'] / 2, a['s']));

    cout << min(b, c);

    return 0;
}