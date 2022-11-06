#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;

int n, len;
char s[MAXN];
int prer[MAXN], pred[MAXN], sufr[MAXN], sufd[MAXN];

void solve()
{
    cin >> n;
    cin >> s + 1;
    len = strlen(s + 1);
    fill(prer, prer + len + 2, 0);
    fill(pred, pred + len + 2, 0);
    fill(sufr, sufr + len + 2, 0);
    fill(sufd, sufd + len + 2, 0);
    for (int i = 1; i <= len; ++i)
    {
        prer[i] = prer[i - 1] + (s[i] == 'R');
    }
    for (int i = 1; i <= len; ++i)
    {
        pred[i] = pred[i - 1] + (s[i] == 'D');
    }
    for (int i = len; i >= 1; --i)
    {
        sufr[i] = sufr[i + 1] + (s[i] == 'R');
    }
    for (int i = len; i >= 1; --i)
    {
        sufd[i] = sufd[i + 1] + (s[i] == 'D');
    }
    if (prer[len] == 0 || pred[len] == 0)
    {
        cout << n << '\n';
        return;
    }
    LL cut = 0;
    for (int i = 1, cur = 1; i <= len; ++i)
    {
        while (s[cur] == 'R')
            ++cur;
        if (s[cur] == 'D')
            ++cur;
        cut += (prer[cur - 1] == 0) ? (n - 1) : sufr[cur];
    }
    for (int i = 1, cur = 1; i <= len; ++i)
    {
        while (s[cur] == 'D')
            ++cur;
        if (s[cur] == 'R')
            ++cur;
        cut += (pred[cur - 1] == 0) ? (n - 1) : sufd[cur];
    }
    cout << (LL)n * n - cut << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        solve();
    }

    return 0;
}