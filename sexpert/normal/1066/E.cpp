#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
const int MOD = 998244353;

int main()
{
    int powtwo[MAXN + 5];
    powtwo[0] = 1;
    for(int i = 1; i < MAXN + 5; i++)
    {
        powtwo[i] = (2*powtwo[i - 1])%MOD;
    }

    int n, m;
    cin >> n >> m;
    string s, t, sprime = "";
    cin >> s >> t;
    int d = t.length() - s.length();
    if(d > 0)
    {
        for(int i = 0; i < d; i++)
            sprime += '0';
        sprime += s;
    }
    if(d < 0)
    {
        for(int i = n - m; i < n; i++)
            sprime += s[i];
    }
    if(d != 0)
        s = sprime;
    long long ans = 0, partial = 0;
    for(int i = 0; i < m; i++)
    {
        if(t[i] == '1')
            partial++;
        long long val = partial * (s[i] - '0') * powtwo[m - 1 - i];
        ans = (ans + val)%MOD;
    }
    cout << ans << endl;
}