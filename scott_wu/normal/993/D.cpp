#include <iostream>
#include <iomanip>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
const int MAXN = 55;

int N;
ll power[MAXN];
int nproc[MAXN];
ll gscore[MAXN];
vector <pair <ll, ll> > v;

ll dp[MAXN][MAXN]; // i computers, j saved, max sum

bool works (ll H)
{
    v.clear();
    for (int i = 0; i < N; i++)
    {
        gscore[i] = nproc[i] * H - power[i];
        v.push_back(make_pair (power[i], gscore[i]));
    }

    sort (v.begin(), v.end());
    reverse (v.begin(), v.end());

    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            dp[i][j] = -1e18;

    dp[0][0] = 0;
    int cloc = 0;
    while (cloc < N)
    {
        int nloc = cloc;
        while (nloc < N && v[cloc].first == v[nloc].first)
            nloc++;

        for (int i = 0; i <= N; i++)
        {
            //cout << dp[cloc][i] << " ";
            for (int j = 0; j <= i && j <= nloc - cloc; j++)
            {
                ll ctot = dp[cloc][i];
                for (int k = cloc; k < nloc - j; k++)
                    ctot += v[k].second;
                int nleft = i - j + (nloc - cloc - j);
                dp[nloc][nleft] = max (dp[nloc][nleft], ctot);
            }
        }
        //cout << "\n";
        cloc = nloc;
    }

    for (int i = 0; i <= N; i++)
    {
        //cout << dp[N][i] << " ";
        if (dp[N][i] >= 0)
            return true;
    }
    return false;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> power[i];
        power[i] *= 1000;
    }
    for (int i = 0; i < N; i++)
        cin >> nproc[i];

    ll lo = 0, hi = 1e12;
    while (lo < hi)
    {
        ll mid = (lo + hi) / 2;
        if (works(mid))
        {
            hi = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }
    cout << lo << "\n";
    return 0;
}