#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

int N;
pair <int, int> coord[MAXN];
int pmax[MAXN], pmin[MAXN], rmax[MAXN], rmin[MAXN];

ll sq (ll m)
{
    return m * m;
}

ll bget (ll m) // first index >= m or N
{
    int lo = 0, hi = N;
    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        if (coord[mid].first >= m)
            hi = mid;
        else
            lo = mid + 1;
    }
    return lo;
}

bool works (ll k)
{
    ll xv = sqrt (k);
    while (sq (xv + 1) <= k)
        xv++;
    
    for (int i = 0; i < N; i++)
    {
        ll xcur = coord[i].first;
        if (xcur < 0)
        {
            ll xend = min (xcur + xv, -xcur);
            int lloc = bget (xend + 1) - 1;
            ll yhi = max (rmax[lloc+1], pmax[i]);
            ll ylo = min (rmin[lloc+1], pmin[i]);
            if (sq(xcur) + sq(yhi) <= k &&
                sq(xcur) + sq(ylo) <= k &&
                sq(yhi - ylo) <= k)
                return true;
        }
        else
        {
            ll xstart = max (xcur - xv, -xcur);
            int lloc = bget (xstart);
            //cout << xstart << " " << lloc << endl;
            ll yhi = max (rmax[i+1], pmax[lloc]);
            ll ylo = min (rmin[i+1], pmin[lloc]);
            if (sq(xcur) + sq(yhi) <= k &&
                sq(xcur) + sq(ylo) <= k &&
                sq(yhi - ylo) <= k)
                return true;
        }
    }
    
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> coord[i].first >> coord[i].second;
    
    sort (coord, coord + N);
    pmin[0] = 1e9;
    pmax[0] = -1e9;
    for (int i = 0; i < N; i++)
    {
        pmin[i+1] = min (pmin[i], coord[i].second);
        pmax[i+1] = max (pmax[i], coord[i].second);
    }
    
    rmin[N] = 1e9;
    rmax[N] = -1e9;
    for (int i = N - 1; i >= 0; i--)
    {
        rmin[i] = min (rmin[i+1], coord[i].second);
        rmax[i] = max (rmax[i+1], coord[i].second);
    }
    
    pmin[0] = pmax[0] = rmin[0] = rmax[0] = 0;
    
    ll lo = 0, hi = min (sq (pmax[N] - pmin[N]), sq (coord[N-1].first - coord[0].first));
    while (lo < hi)
    {
        ll mid = (lo + hi) / 2;
        if (works (mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    
    cout << lo << endl;
    //system ("Pause");
    return 0;
}