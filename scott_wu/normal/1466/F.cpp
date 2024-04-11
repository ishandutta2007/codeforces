#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 500100;
const ll MOD = 1e9 + 7;

int N, M;
int par[MAXN];
int good[MAXN];

vector <int> ans;

int cfind (int x)
{
    if (par[x] == x) return x;
    return par[x] = cfind (par[x]);
}

bool uni (int x, int y)
{
    x = cfind (x);
    y = cfind (y);
    if (x == y) return false;
    if (good[x] && good[y]) return false;

    par[x] = y;
    if (good[x]) good[y] = true;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N >> M;
    for (int i = 0; i < MAXN; i++)
        par[i] = i;

    for (int i = 0; i < N; i++)
    {
        int K; cin >> K;
        if (K == 1)
        {
            int x; cin >> x;
            x--;
            x = cfind (x);

            if (!good[x])
            {
                good[x] = 1;
                ans.push_back (i);
            }
        }
        else
        {
            int x, y; cin >> x >> y;
            x--, y--;

            if (uni (x, y))
                ans.push_back (i);
        }
    }

    sort (ans.begin(), ans.end());
    ll m = 1;
    for (int i = 0; i < ans.size(); i++)
        m = (m * 2) % MOD;
    cout << m << " " << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
    {
        if (i) cout << " ";
        cout << ans[i] + 1;
    }
    cout << "\n";
}