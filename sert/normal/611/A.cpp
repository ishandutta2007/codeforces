#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

ll a[N];
ll n, m, t, k;
string s;
int ans;

int main() {
    //freopen("a.in", "r", stdin);

    cin >> n;
    cin >> s >> s;
    if (s == "week") {
        ans = 52;
        if (n == 5 || n == 6)
            ans++;
    } else {
        ans = 12;
        if (n == 30) ans = 11;
        if (n == 31) ans = 7;
    }
    cout << ans;

    return 0;
}