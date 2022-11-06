#include <iostream>
#include <algorithm>

using namespace std;

using LL = long long;

constexpr int MAXN = 1000000 + 9;

int n, m;
char s[MAXN];
bool col[MAXN];
int row[MAXN];
int sum[MAXN];

void solve()
{
    cin >> n >> m;
    cin >> s;
    fill(col, col + m, false);
    fill(sum, sum + n * m, 0);
    fill(row, row + m, 0);
    int ansc = 0;
    for (int i = 0; i < n * m; ++i)
    {
        int r = i / m, c = i % m;
        if (!col[c] && s[i] == '1')
        {
            col[c] = true;
            ++ansc;
        }
        sum[i] = s[i] == '1';
        if (i > 0)
            sum[i] += sum[i - 1];
        if (i < m)
        {
            if (sum[i] > 0)
                ++row[c];
        }
        else
        {
            if (sum[i] - sum[i - m] > 0)
                ++row[c];
        }
        cout << ansc + row[c] << ' ';
    }
    cout << '\n';
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