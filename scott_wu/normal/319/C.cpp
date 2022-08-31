#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;
typedef long double ld;
const int MAXN = 100100;

int N;
ll a[MAXN], b[MAXN];
ll dp[MAXN];

pair <ll, ll> hull[MAXN]; //slope, yint
int nhull;

ll func (ll xval, int hnum)
{
    return xval * hull[hnum].first + hull[hnum].second;
}

ld inter (int left, int right)
{
    return ((ld) hull[right].second - hull[left].second) / ((ld) hull[left].first - hull[right].first);
}

ll search (ll xval)
{
    if (nhull == 1)
        return func (xval, 0);
    if (func (xval, 0) <= func (xval, 1))
        return func (xval, 0);
    if (func (xval, nhull - 2) >= func (xval, nhull - 1))
        return func (xval, nhull - 1);
    
    int lo = 1, hi = nhull - 2;
    while (lo < hi)
    {
        int mid = (lo + hi + 1) / 2;
        if (func (xval, mid - 1) <= func (xval, mid))
            hi = mid - 1;
        else
            lo = mid;
    }
    return func (xval, lo);
}

void add (pair <ll, ll> x)
{
    hull[nhull] = x;
    
    while (nhull >= 2 && inter (nhull - 2, nhull) >= inter (nhull - 1, nhull))
    {
        hull[nhull - 1] = hull[nhull];
        nhull--;
    }
    nhull++;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> a[i];
    for (int i = 0; i < N; i++)
        cin >> b[i];
    
    dp[0] = b[0];
    add (make_pair (b[0], b[0]));
    for (int i = 1; i < N; i++)
    {
        dp[i] = search (a[i] - 1) + b[i];
        add (make_pair (b[i], dp[i]));
    }
    
    cout << dp[N-1] << "\n";
    //system ("Pause");
    return 0;
}