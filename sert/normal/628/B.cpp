#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;
const ll md = 1e9 + 7;

char ss[N];
string s;
long long ans;
int n;
int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    gets(ss); s = ss;
    n = s.length();
    for (int i = 0; i < n; i++)
        if (s[i] == '0' || s[i] == '4' || s[i] == '8')
            ans++;
    for (int i = 1; i < n; i++) {
        if (((s[i - 1] - '0') * 10 + s[i] - '0') % 4 == 0) ans += i;
    }
    cout << ans;


    return 0;
}