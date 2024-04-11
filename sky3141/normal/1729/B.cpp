#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;



void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t;
    for (int i = n - 1; i >= 0; )
    {
        if (s[i] == '0')
        {
            t.push_back('a' - 1 + ((s[i - 2] - '0') * 10 + s[i - 1] - '0'));
            i -= 3;
        }
        else
        {
            t.push_back('a' - 1 + s[i] - '0');
            --i;
        }
    }
    reverse(t.begin(), t.end());
    cout << t << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
}