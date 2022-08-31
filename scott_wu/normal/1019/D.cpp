#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAXN = 2100;

int N;
ll S;
pair <ll, ll> ss[MAXN];
ll x[MAXN], y[MAXN];
int ord[MAXN], loc[MAXN];

pair <pair <ll, ll>, int> ploc[MAXN*MAXN];

ll area (int a, int b, int c) // signed
{
    ll xa = x[a], ya = y[a];
    ll xb = x[b], yb = y[b];
    ll xc = x[c], yc = y[c];
    return xa * yb + xb * yc + xc * ya - xa * yc - xc * yb - xb * ya;
}

bool cmpc (pair <ll, ll> left, pair <ll, ll> right)
{
    return left.first * right.second > right.first * left.second;
}

bool cmp (pair <pair <ll, ll>, int> left, pair <pair <ll, ll>, int> right)
{
    return cmpc (left.first, right.first);
}

void put_res (int a, int b, int c)
{
    cout << "Yes\n";
    cout << x[a] << " " << y[a] << "\n";
    cout << x[b] << " " << y[b] << "\n";
    cout << x[c] << " " << y[c] << "\n";
}

int main()
{
    cin >> N >> S;
    S *= 2;
    for (int i = 0; i < N; i++)
    {
        cin >> ss[i].second >> ss[i].first;
    }
    sort (ss, ss + N);
    for (int i = 0; i < N; i++)
    {
        x[i] = ss[i].second;
        y[i] = ss[i].first;
    }

    int cc = 0;
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
        {
            ll xd = x[j] - x[i];
            ll yd = y[j] - y[i];

            if (yd < 0)
            {
                xd = -xd;
                yd = -yd;
            }
            if (yd == 0)
            {
                if (xd < 0)
                    xd = -xd;
            }

            ploc[cc].first = make_pair (xd, yd);
            ploc[cc].second = i * N + j;
            cc++;
        }
    sort (ploc, ploc + cc, cmp);

    for (int i = 0; i < N; i++)
    {
        ord[i] = i;
        loc[i] = i;
    }

    for (int i = 0; i < cc; i++)
    {
        int left = ploc[i].second / N, right = ploc[i].second % N;

        // do some stuff
        int lo = 0, hi = N - 1;
        while (lo < hi)
        {
            int mid = (lo + hi) / 2;
            ll A = area (left, right, ord[mid]);
            if (A < -S)
                lo = mid + 1;
            else
                hi = mid;
        }
        if (area (left, right, ord[lo]) == -S)
        {
            put_res (left, right, ord[lo]);
            return 0;
        }

        lo = 0, hi = N - 1;
        while (lo < hi)
        {
            int mid = (lo + hi) / 2;
            ll A = area (left, right, ord[mid]);
            if (A < S)
                lo = mid + 1;
            else
                hi = mid;
        }
        if (area (left, right, ord[lo]) == S)
        {
            put_res (left, right, ord[lo]);
            return 0;
        }
        swap (ord[loc[left]], ord[loc[right]]);
        swap (loc[left], loc[right]);
    }
    cout << "No\n";
    return 0;
}