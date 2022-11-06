#include <iostream>
#include <algorithm>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;
constexpr LL INF = 1000000000000000000LL + 9;

int n, c, q;
char s[MAXN];
LL l[45], r[45];
LL len[45];

void solve()
{
    cin >> n >> c >> q;
    cin >> s;
    len[0] = n;
    for (int i = 1; i <= c; ++i)
    {
        cin >> l[i] >> r[i];
        --l[i];
        len[i] = len[i - 1] + (r[i] - l[i]);
        len[i] = min(len[i], INF);
    }
    for (int i = 0; i < q; ++i)
    {
        LL x;
        cin >> x;
        --x;
        while (x >= n)
        {
            int pos = upper_bound(len, len + c + 1, x) - len;
            x = x - len[pos - 1] + l[pos];
        }
        cout << s[x] << '\n';
    }
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