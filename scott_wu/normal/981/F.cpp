#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <cmath>

using namespace std;
const int MAXN = 1000100;
typedef long long ll;

int N, L;
ll A[MAXN], B[MAXN];

int bsearch (ll k)
{
    int lo = 0, hi = 3 * N - 1;
    while (lo < hi)
    {
        int mid = (lo + hi + 1) / 2;
        if (k < B[mid])
        {
            hi = mid - 1;
        }
        else
            lo = mid;
    }
    return lo;
}

pair <int, int> get_offset (int cloc, int x)
{
    ll lo = A[cloc] - x, hi = A[cloc] + x;
    int nlo = bsearch(lo - 1), nhi = bsearch(hi);
    nlo++;
    return make_pair (nlo - cloc, nhi - cloc);
}

bool works (int x)
{
    int offset_lo = -1e9, offset_hi = 1e9;
    //cout << x << "\n";
    for (int i = 0; i < N; i++)
    {
        pair <int, int> offset_range = get_offset(i, x);
        //cout << A[i] << " " << x << " " << A[i] - x << " " << A[i] + x << "\n";
        //cout << offset_range.first << " " << offset_range.second << "\n";
        offset_lo = max (offset_lo, offset_range.first);
        offset_hi = min (offset_hi, offset_range.second);
    }
    return offset_lo <= offset_hi;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N >> L;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < N; i++)
        cin >> B[i];
    for (int i = N; i < 3 * N; i++)
        B[i] = B[i-N] + L;
    for (int i = 0; i < N; i++)
        A[i] += L;

    sort (A, A + N);
    sort (B, B + 3 * N);

    int lo = 0, hi = L / 2;
    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        if (works (mid))
        {
            hi = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }
    cout << lo << "\n";
}