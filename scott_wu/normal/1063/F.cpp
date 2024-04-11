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
const int MAXN = 500100;
const ll MOD = 1e9 + 9;

int N;
string S;

ll mpow[MAXN];
ll hpre[MAXN];
int dp[MAXN];

map <ll, int> hashes;

ll ghash (int lo, int len)
{
    return hpre[lo+len] - mpow[len] * hpre[lo];
}

bool put_hash (int lo, int len)
{
    ll h = ghash (lo, len);
    if (hashes.find(h) == hashes.end())
    {
        hashes[h] = lo;
        return false;
    }
    return true;
}

bool has_hash (int lo, int len, int e)
{
    ll h = ghash (lo, len);
    if (hashes.find(h) != hashes.end() && hashes[h] >= e) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N >> S;

    mpow[0] = 1;
    for (int i = 0; i < N; i++)
    {
        hpre[i+1] = MOD * hpre[i] + S[i];
        mpow[i+1] = MOD * mpow[i];
    }

    dp[N] = 0;
    hashes[0] = N;
    for (int i = N - 1; i >= 0; i--)
    {
        int cs = dp[i+1] + 1;
        while (true)
        {
            if (has_hash (i + 1, cs - 1, i + cs) || has_hash (i, cs - 1, i + cs))
                break;
            cs--;
        }
        dp[i] = cs;
        for (int j = cs; j >= 1; j--)
            if (put_hash (i, j)) break;
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
        ans = max (ans, dp[i]);
    cout << ans << "\n";
}