#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;

int n;
char s[MAXN];

void solve()
{
    int a, b, ab, ba;
    cin >> a >> b >> ab >> ba;
    cin >> s;
    n = a + b + 2 * (ab + ba);
    int cnta = 0, cntb = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == 'A')
            ++cnta;
        else
            ++cntb;
    }
    if (a + ab + ba != cnta || b + ab + ba != cntb)
    {
        cout << "NO\n";
        return;
    }
    vector<int> abab, baba, ababa;
    for (int i = 0; i < n; )
    {
        int prei = i;
        while (i + 1 < n && s[i] != s[i + 1])
        {
            ++i;
        }
        ++i;
        int len = i - prei;
        int t = len / 2;
        if (t > 0)
        {
            if (len & 1) // ababa
            {
                ababa.push_back(t);
            }
            else
            {
                if (s[prei] == 'A') // abab
                {
                    abab.push_back(t);
                }
                else
                {
                    baba.push_back(t);
                }
            }
        }
    }
    sort(abab.begin(), abab.end());
    sort(baba.begin(), baba.end());
    sort(ababa.begin(), ababa.end());
    for (int &cur : abab)
    {
        int t = min(cur, ab);
        cur -= t;
        ab -= t;
    }
    for (int &cur : baba)
    {
        int t = min(cur, ba);
        cur -= t;
        ba -= t;
    }
    for (int &cur : ababa)
    {
        int t = min(cur, ab);
        cur -= t;
        ab -= t;
    }
    for (int &cur : ababa)
    {
        int t = min(cur, ba);
        cur -= t;
        ba -= t;
    }
    for (int &cur : abab)
    {
        if (cur > 0) --cur;
        int t = min(cur, ba);
        ba -= t;
    }
    for (int &cur : baba)
    {
        if (cur > 0) --cur;
        int t = min(cur, ab);
        ab -= t;
    }
    if (ab != 0 || ba != 0)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}