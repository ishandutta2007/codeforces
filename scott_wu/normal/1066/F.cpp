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
const int MAXN = 200100;

int N;
pair <ll, ll> pt[MAXN];
map <int, pair <ll, ll> > mm; // min x, max x
ll dp[MAXN][2];

ll dget (int a, int b, int c, int d)
{
    return abs (a - c) + abs (b - d);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> pt[i].first >> pt[i].second;
        ll rloc = max (pt[i].first, pt[i].second);
        ll rt = pt[i].first;
        if (rt == rloc) rt += (rloc - pt[i].second);
        if (mm.find(rloc) == mm.end())
            mm[rloc] = make_pair (2e9, 0);
        mm[rloc].first = min (mm[rloc].first, rt);
        mm[rloc].second = max (mm[rloc].second, rt);
    }

    int x[2] = {0, 0}, y[2] = {0, 0};
    dp[0][0] = dp[0][1] = 0;
    int cloc = 1;

    for (auto it = mm.begin(); it != mm.end(); it++)
    {
        ll ctot = it -> first, nlo = it -> second.first, nhi = it -> second.second;
        ll xlo = min (ctot, nlo), ylo = min (ctot, 2 * ctot - nlo);
        ll xhi = min (ctot, nhi), yhi = min (ctot, 2 * ctot - nhi);
        
        dp[cloc][0] = min (dp[cloc-1][0] + dget (x[0], y[0], xhi, yhi),
                           dp[cloc-1][1] + dget (x[1], y[1], xhi, yhi));
        dp[cloc][1] = min (dp[cloc-1][0] + dget (x[0], y[0], xlo, ylo),
                           dp[cloc-1][1] + dget (x[1], y[1], xlo, ylo));
        dp[cloc][0] += nhi - nlo;
        dp[cloc][1] += nhi - nlo;
        x[0] = xlo;
        y[0] = ylo;
        x[1] = xhi;
        y[1] = yhi;

        //cout << cloc << " " << ctot << " " << dp[cloc][0] << " " << dp[cloc][1] << "\n";
        cloc++;
    }

    cout << min (dp[cloc-1][0], dp[cloc-1][1]) << "\n";
}