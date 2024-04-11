#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXN = 5100;
const long long MOD = 1000000007;

string s, t;
ll num[MAXN];

int main()
{
    cin >> s >> t;
    int n = s.length(), m = t.length();
    for (int i = 0; i < n; i++)
        num[i] = 1;
    num[n] = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = n - 1; j >= 0; j--)
            if (t[i] == s[j])
                num[j+1] = (num[j] + num[j+1]) % MOD;
    }
    ll ans = 0;
    for (int i = 0; i <= n; i++)
        ans = (ans + num[i]) % MOD;
    ans = ans - n;
    cout << ans << "\n";
    //system ("Pause");
    return 0;
}