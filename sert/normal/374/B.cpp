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

    s.push_back(s.back());
    ll ans = 1;
    ll len = 0;
    char lst = '@';
    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] + s[i + 1] - '0' * 2 == 9) {
            if (lst != '@')
                len++;
            else
                lst = s[i];
        } else {
            if (s[i] == lst)
                ans *= (len + 3) / 2;
            lst = '@';
            len = 0;
        }
    }

    cout << ans;

    return 0;
}