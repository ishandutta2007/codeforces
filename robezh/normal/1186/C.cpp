#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e6 + 50;

int n, m;
string s, t;
int ss[N], st[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s >> t;
    n = s.length();
    m = t.length();
    int cnt1 = 0;
    s = " " + s;
    t = " " + t;
    for(int i = 1; i <= n; i++) ss[i] = ss[i-1] + (s[i] == '1');
    for(int i = 1; i <= m; i++) cnt1 += (t[i] == '1');
    int res = 0;
    for(int i = m; i <= n; i++) {
        int rem = (ss[i] - ss[i-m]);
        res += (rem % 2 == cnt1 % 2);
    }
    cout << res << endl;


}