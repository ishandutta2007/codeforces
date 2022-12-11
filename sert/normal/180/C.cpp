#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = (ll)1e18 + 7;
const ll o5 = 716327852;
const int N = 1e5 + 2;

bitset<N> a, b;

int main() {
    //freopen("a.in", "r", stdin);
    string s;
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n; i++) {
        if ('A' <= s[i] && s[i] <= 'Z')
            a[i] = 1;
        else
            a[i] = 0;
        b[i] = 0;
    }

    int ans = (a ^ b).count();
    //cerr << ans << "\n";

    int cur = ans;

    for (int i = 0; i < n; i++) {
        b[i] = 1;
        if (b[i] == a[i])
            cur--;
        else
            cur++;
        ans = min(ans, cur);
        //cerr << a << " " << b << " " << (a ^ b).count() << "\n";
    }

    cout << ans;

    return 0;
}