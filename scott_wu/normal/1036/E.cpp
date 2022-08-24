#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <complex>
#include <set>

using namespace std;
typedef long long ll;
typedef complex<ll> point;
const int MAXN = 1100;
const ll BAD = 1e18;

int N;
int x[MAXN], y[MAXN], x2[MAXN], y2[MAXN];
point A[MAXN], B[MAXN];

int gcf (int a, int b)
{
    if (b == 0) return a;
    return gcf (b, a % b);
}

int npoint (int a)
{
    return gcf (abs (x[a] - x2[a]), abs (y[a] - y2[a])) + 1;
}

ll cross (point left, point right)
{
    return imag(conj(left) * right);
}

ll ang_cross (point a, point b, point c)
{
    return cross (b - a, c - a);
}

ll inter (int l, int r)
{
    ll c1 = ang_cross (A[l], B[l], A[r]), c2 = ang_cross (A[l], B[l], B[r]);
    ll c3 = ang_cross (A[r], B[r], A[l]), c4 = ang_cross (A[r], B[r], B[l]);
    // both on one side, or the two segments lie on the same line (assume they can't intersect)
    if ((c1 < 0 == c2 < 0) && (c1 > 0 == c2 > 0))
        return BAD;
    if ((c3 < 0 == c4 < 0) && (c3 > 0 == c4 > 0))
        return BAD;
    point cp = c1 * B[r] - c2 * A[r];
    ll delta = c1 - c2;
    //cout << l << " " << r << " " << delta << endl;
    if (cp.real() % delta != 0 || cp.imag() % delta != 0)
        return BAD;
    return cp.real() / delta * (ll) 1e7 + cp.imag() / delta;
}

set <ll> mm;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N;

    ll ans = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> x[i] >> y[i] >> x2[i] >> y2[i];
        ans += npoint (i);
        A[i] = point (x[i], y[i]);
        B[i] = point (x2[i], y2[i]);
    }

    for (int i = 0; i < N; i++)
    {
        mm.clear();
        for (int j = i + 1; j < N; j++)
        {
            ll v = inter (i, j);
            if (v < 1e15)
                mm.insert(v);
        }
        ans -= mm.size();
    }

    cout << ans << "\n";
}