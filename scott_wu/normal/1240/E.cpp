#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int MAXN = 1000100;

int N, yhi, xhi;
int nc[MAXN];
int ps[MAXN];
int nnext[MAXN];
int arr[MAXN];

int gg (int Y, int X)
{
    int ans = 1e9;
    int rb = (2 * X) % Y;
    for (int i = (2 * X) / Y; i <= yhi / Y; i++)
    {
        int np = i * Y + rb;
        int n = nnext[np];
        if (n != -1)
            ans = min (ans, n / Y - (n - 2 * X) / Y);
    }

    /*for (int i = 0; i < N; i++)
    {
        if (arr[i] >= 2 * X)
        {
            ans = min (ans, arr[i] / Y - (arr[i] - 2 * X) / Y);
        }
    }*/

    rb = X % Y;
    
    int lo0 = 1e9, lo1 = 1e9;
    for (int i = X / Y; i <= yhi / Y; i++)
    {
        int np = i * Y + rb;
        int n = nnext[np];
        if (n != -1 && n < np + Y)
        {
            int c = (n / Y - (n - X) / Y);
            if (c < lo1)
            {
                lo1 = c;
                if (lo0 > lo1) swap (lo0, lo1);
            }

            if (nc[n] > 1)
            {
                if (c < lo1) lo1 = c;
            }
            else
            {
                n = nnext[n+1];
                if (n != -1 && n < np + Y)
                {
                    //cout << n << "\n";
                    c = (n / Y - (n - X) / Y);
                    if (c < lo1)
                    {
                        lo1 = c;
                        if (lo0 > lo1) swap (lo0, lo1);
                    }
                }
            }
        }
    }
    /*for (int i = 0; i < N; i++)
        if (arr[i] >= X)
        {
            int np = (arr[i] / Y - (arr[i] - X) / Y);
            if (np < lo1)
            {
                lo1 = np;
                if (lo0 > lo1) swap (lo0, lo1);
            }
        }*/
    ans = min (ans, lo0 + lo1);
    return ans;
}

int gogo (int Y)
{
    ll ctot = 0;
    for (int i = 0; i <= yhi / Y; i++)
    {
        int nq = ps[(i+1)*Y] - ps[i*Y];
        ctot += nq * i;
    }
    int hi = min (ctot, (ll) xhi);
    int lo = min (ctot - 2 * (ctot / Y + 1), (ll) xhi);
    lo = max (lo, 0);

    //cout << ctot << "\n";
    while (lo < hi)
    {
        int mid = (lo + hi + 1) / 2;
        int gcost = gg (Y, mid);
        //cout << mid << " " << gcost << "\n";
        if (ctot - gcost >= mid)
        {
            lo = mid;
        }
        else hi = mid - 1;
    }
    if (lo <= 1) return 0;
    //cout << Y << " " << lo << "\n";
    return lo;
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < MAXN; i++)
        nc[i] = 0;
    yhi = 0;
    for (int i = 0; i < N; i++)
    {
        int t; cin >> t;
        nc[t]++;
        yhi = max (yhi, t);
        arr[i] = t;
    }
    sort (arr, arr + N);
    xhi = arr[N-1] / 2;
    if (N > 1) xhi = max (xhi, arr[N-2]);

    ps[0] = 0;
    for (int i = 1; i < MAXN; i++)
        ps[i] = ps[i-1] + nc[i-1];
    nnext[MAXN - 1] = -1;
    for (int i = MAXN - 2; i >= 0; i--)
    {
        if (nc[i])
            nnext[i] = i;
        else
            nnext[i] = nnext[i+1];
    }

    ll ans = 0;
    for (int i = 2; i <= yhi; i++)
    {
        ll gb = gogo (i);
        ans = max (ans, gb * (ll) i);
    }
    cout << ans << "\n";
}