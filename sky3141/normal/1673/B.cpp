#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;

int n;
char s[MAXN];
// int f[MAXN];

bool solve()
{
    bool ex[128] = {};
    cin >> s;
    int len = strlen(s);
    for (int i = 0; i < len; ++i)
    {
        ex[s[i]] = true;
    }
    for (char a = 'a'; a <= 'z'; ++a)
    {
        for (char b = 'a'; b <= 'z'; ++b)
        {
            if (!ex[a] || !ex[b])
                continue;
            int ma = 0, mb = 0;
            for (int i = 0; i < len; ++i)
            {
                if (s[i] == a)
                {
                    ++ma;
                    --mb;
                }
                if (s[i] == b)
                {
                    ++mb;
                    --ma;
                }
                ma = max(ma, 0);
                mb = max(mb, 0);
                if (ma >= 2 || mb >= 2)
                    return false;
            }
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int t = 0; t < n; ++t)
    {
        cout << (solve() ? "YES\n" : "NO\n");
    }

    return 0;
}