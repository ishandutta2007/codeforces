#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

int N, M, X, Y;
pair <int, int> hi[MAXN];
pair <int, int> lo[MAXN];

int nhull;
pair <int, int> hull[MAXN];
int cloc;

bool bad (pair <int, int> a, pair <int, int> b, pair <int, int> c) // is c over a-b?
{
    ll x1 = a.first, x2 = b.first, x3 = c.first;
    ll y1 = a.second, y2 = b.second, y3 = c.second;
    
    return y1 * (x2 - x3) + y2 * (x3 - x1) <= y3 * (x2 - x1);
}

void add (pair <int, int> x)
{
    hull[nhull] = x;
    while (nhull >= 2)
    {
        if (!bad (hull[nhull-2], hull[nhull], hull[nhull-1]))
        {
            hull[nhull-1] = hull[nhull];
            nhull--;
        }
        else
            break;
    }
    nhull++;
}

bool check (pair <int, int> x)
{
    //cout << hull[cloc].first << " " << hull[cloc].second << " " << hull[cloc+1].first << " " << hull[cloc+1].second << " " << x.first << " " << x.second << "\n";
    if (x.first >= hull[nhull-1].first)
        return false;

    while (hull[cloc+1].first < x.first)
        cloc++;
    
    return !bad (hull[cloc], hull[cloc+1], x);
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    cin >> N >> M >> X >> Y;
    for (int i = 0; i < N; i++)
        cin >> hi[i].first >> hi[i].second;
    for (int i = 0; i < M; i++)
        cin >> lo[i].first >> lo[i].second;
    
    sort (hi, hi + N);
    sort (lo, lo + M);
    nhull = 1;
    hull[0] = make_pair (0, 0);
    for (int i = 0; i < M; i++)
        hull[0].second = max (hull[0].second, lo[i].second);
    
    for (int i = 0; i < M; i++)
    {
        if (i == M - 1 || (lo[i].first != lo[i+1].first))
            add (lo[i]);
    }
    
    cloc = 0;
    bool good = true;
    for (int i = 0; i < N; i++)
        if (!check (hi[i]))
            good = false;
    
    if (good)
        cout << "Min\n";
    else
        cout << "Max\n";
    
    return 0;
}