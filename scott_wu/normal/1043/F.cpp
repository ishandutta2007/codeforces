#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 300100;

int N;
int hv[MAXN];
int ntot[MAXN]; // num mult
bool ghas[MAXN];
int dp[MAXN];
vector <int> plist[MAXN];
int pprime[MAXN];

bool figure (int x)
{
    // do gcds of x sum to N?
    int np = plist[x].size();

    int ans = 0;
    for (int i = 0; i < (1 << np); i++)
    {
        int ct = 1, s = 1;
        for (int j = 0; j < np; j++)
            if (i & (1 << j))
            {
                ct *= plist[x][j];
                s = -s;
            }
        ans += ntot[ct] * s;
    }
    return (ans != 0);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    for (int i = 0; i < MAXN; i++)
        pprime[i] = -1;
    for (int i = 2; i < MAXN; i++)
    {
        if (pprime[i] == -1)
        {
            plist[i].push_back(i);
            for (int j = 2 * i; j < MAXN; j += i)
                pprime[j] = i;
        }
        else
        {
            int nv = i / pprime[i];
            for (int x : plist[nv])
                plist[i].push_back(x);
            if (plist[i].back() != pprime[i])
                plist[i].push_back(pprime[i]);
        }
    }

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x; cin >> x;
        hv[x] = 1;
    }
    for (int i = 1; i < MAXN; i++)
    {
        ntot[i] = 0;
        for (int j = i; j < MAXN; j += i)
            ntot[i] += hv[j];
    }

    for (int i = 1; i < MAXN; i++)
    {
        ghas[i] = figure (i);
    }

    for (int i = MAXN - 1; i >= 1; i--)
    {
        if (hv[i])
            dp[i] = 1;
        else
            dp[i] = 1e9;
        for (int j = 2 * i; j < MAXN; j += i)
            if (ghas[j/i])
                dp[i] = min (dp[i], 1 + dp[j]);
    }
    if (dp[1] > 1e6)
    {
        cout << "-1\n";
        return 0;
    }
    cout << dp[1] << "\n";
}