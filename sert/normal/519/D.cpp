#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <map>
#include <string>
using namespace std;
const long long N = 1e5 + 34;
const long long LOT = 1e11;
typedef long long ll;
map<ll, ll> m;
ll sum, code, c[30], ans, n;
string s;
int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    for (int i = 0; i < 26; i++)
        cin >> c[i];
    cin >> s;
    n = s.length();
    for (int i = 0; i < n; i++) {
        code = sum + LOT * (s[i] - 'a');
        ans += m[code];
        code += c[s[i] - 'a'];
        sum += c[s[i] - 'a'];
        m[code]++;
    }
    cout << ans;
}