#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;

char nxt[128];
bool used[128];

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    memset(nxt, 0, sizeof(nxt));
    memset(used, 0, sizeof(used));
    string ans;
    for (auto c : s)
    {
        if (!nxt[c])
        {
            for (char t = 'a'; t <= 'z'; ++t)
            {
                if (!used[t])
                {
                    for (char tmp = t; tmp; tmp = nxt[tmp])
                    {
                        if (tmp == c)
                            goto conti;
                    }
                    nxt[c] = t;
                    used[t] = true;
                    break;
                }
                conti:;
            }
            if (!nxt[c])
            {
                for (char t = 'a'; t <= 'z'; ++t)
                {
                    if (!used[t])
                    {
                        nxt[c] = t;
                        used[t] = true;
                        break;
                    }
                }
            }
        }
        ans.push_back(nxt[c]);
    }
    cout << ans << '\n';
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