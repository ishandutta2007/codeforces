#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;
typedef double ld;
const int MAXN = 100100;
const int MAXA = 20;
const ld PI = acos (-1.0);

int N, M;
pair <ll, ll> pt[MAXN];
ld pdist[MAXN];
ld pang[MAXN];
ld hlo[MAXN], hhi[MAXN];
ld nhi[MAXN];
int nnext[2*MAXN];
ll njump[MAXN][MAXA];

bool works (ld d)
{
    for (int i = 0; i < N; i++)
    {
        ld v = acos (d / pdist[i]);
        hlo[i] = pang[i] - v;
        if (hlo[i] <= -PI) hlo[i] += 2 * PI;
        hhi[i] = pang[i] + v;
        if (hhi[i] >= PI) hhi[i] -= 2 * PI;

        nhi[i] = hhi[i];
    }
    sort (nhi, nhi + N);

    for (int i = 0; i < 2 * N; i++)
        nnext[i] = i - N;

    for (int i = 0; i < N; i++)
    {
        int xloc = lower_bound(nhi, nhi + N, hhi[i]) - nhi;
        int yloc;
        if (hlo[i] >= nhi[N-1])
            yloc = 0;
        else
            yloc = lower_bound(nhi, nhi + N, hlo[i]) - nhi;
        yloc--;
        if (yloc >= xloc) yloc -= N;
        nnext[xloc] = max (nnext[xloc], yloc);
    }

    for (int i = 0; i < N; i++)
        nnext[i+N] = nnext[i] + N;
    for (int i = 1; i < 2 * N; i++)
        nnext[i] = max (nnext[i], nnext[i-1]);

    for (int i = 0; i < N; i++)
        njump[i][0] = i + N - nnext[i+N];

    int cloc = 0;
    for (int i = 0; i < N; i++)
    {
        cloc -= njump[cloc][0];
        if (cloc < 0) cloc += N;
    }

    int ndist = 0;
    for (int i = 0; i < M; i++)
    {
        ndist += njump[cloc][0];
        if (ndist >= N) return true;
        cloc -= njump[cloc][0];
        if (cloc < 0) cloc += N;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> pt[i].first >> pt[i].second;

    cout << fixed << setprecision(9);

    ld dlo = 1e9;
    for (int i = 0; i < N; i++)
    {
        if (pt[i].first == 0 && pt[i].second == 0)
        {
            cout << 0. << "\n";
            return 0;
        }
        pdist[i] = sqrt(pt[i].first * pt[i].first + pt[i].second * pt[i].second);
        pang[i] = atan2(pt[i].second, pt[i].first);
        dlo = min (dlo, pdist[i]);
    }

    //works (1.0);
    //return 0;

    ld lo = 0.0, hi = dlo;
    for (int run = 0; run < 40; run++)
    {
        ld mid = (lo + hi) / 2;
        if (works (mid))
        {
            lo = mid;
        }
        else
            hi = mid;
    }
    cout << lo << "\n";
}