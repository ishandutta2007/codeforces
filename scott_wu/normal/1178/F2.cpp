#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
 
using namespace std;
typedef long long ll;
const int MAXM = 1000100;
const int MAXN = 510;
const ll MOD = 998244353;

int N, M;
int arr[MAXM];
vector <int> oloc[MAXN];
int lo[MAXN], hi[MAXN];
ll dp[MAXN][MAXN]; // dp from lo[i] to hi[j]
ll fscore[MAXN];
vector <pair <int, pair <int, int> > > v;

ll get_dp (int x, int y)
{
    // ind x to y
    if (x == y) return 1;
    y--;
    if (lo[arr[x]] == x && hi[arr[y]] == y)
        return dp[arr[x]][arr[y]];
    return 0;
}

bool contains (int x, int y, int k)
{
    if (lo[k] > y || hi[k] < x)
        return false;
    /*for (int i : oloc[k])
        if (i >= x && i <= y)
            return true;
    return false;*/
    //cout << x << " " << y << " " << k << endl;
    vector<int>::iterator it = lower_bound (oloc[k].begin(), oloc[k].end(), x);
    if (it == oloc[k].end() || *it > y) return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    for (int i = 0; i < MAXN; i++)
    {
        oloc[i].clear();
        lo[i] = 1e9;
        hi[i] = -1;
    }

    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int k; cin >> k;
        k--;
        arr[i] = k;
        oloc[k].push_back(i);
        lo[k] = min (lo[k], i);
        hi[k] = max (hi[k], i);
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            int x = lo[i], y = hi[j];
            if (x > y || hi[i] > y || lo[j] < x)
                continue;
            bool bad = false;
            int mlo = 1e9;
            for (int k = 0; k < N; k++)
            {
                if (!contains (x, y, k)) continue;
                if (lo[k] < x || hi[k] > y)
                {
                    bad = true;
                    break;
                }
                mlo = min (mlo, k);
            }
            if (bad) continue;
            v.push_back (make_pair (-mlo, make_pair (i, j)));
        }

    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            dp[i][j] = 0;

    sort (v.begin(), v.end());

    for (int vx = 0; vx < v.size(); vx++)
    {
        int ind = -v[vx].first;
        int x = v[vx].second.first, y = v[vx].second.second;
        //cout << ind << " " << x << " " << y << endl;
        if (vx == 0 || v[vx].first != v[vx-1].first)
        {
            fscore[ind] = 1;
            for (int i = 0; i + 1 < oloc[ind].size(); i++)
            {
                int left = oloc[ind][i], right = oloc[ind][i+1];
                fscore[ind] = (fscore[ind] * get_dp (left + 1, right)) % MOD;
            }
        }

        int hlo = lo[x];
        int hhi = hi[y];
        int ilo = lo[ind];
        int ihi = hi[ind];

        ll l = 0, r = 0;
        for (int i = 0; i < N; i++)
        {
            if (lo[i] >= hlo && lo[i] <= ilo)
            {
                l += get_dp (hlo, lo[i]) * get_dp (lo[i], ilo);
                l %= MOD;
            }
            if (hi[i] <= hhi && hi[i] >= ihi)
            {
                r += get_dp (ihi + 1, hi[i] + 1) * get_dp (hi[i] + 1, hhi + 1);
                r %= MOD;
            }
        }
        dp[x][y] = (((l * r) % MOD) * fscore[ind]) % MOD;
        //cout << x << " " << y << " " << dp[x][y] << "\n";
    }
    int l = arr[0], r = arr[M-1];
    cout << dp[l][r] << "\n";
}