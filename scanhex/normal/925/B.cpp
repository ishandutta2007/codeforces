#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#define div scankex

using namespace std;

typedef long long ll;

mt19937 rnd(228);

ll div(ll a, ll b)
{
    return a / b + bool(a % b);
}



vector <pair <int, int> > x;

int n, a, b;

void print(int k1, int k2)
{
    int cnt = 0;
    vector <bool> die(n);
    vector <int> l, r;
    for (int i = n - 1; i >= 0; i--)
    {
        if (cnt == k1)
        {
            break;
        }
        if (x[i].first * (ll) k1 >= a)
        {
            cnt++;
            l.push_back(x[i].second);
            die[i] = true;
        }
    }
    assert(cnt == k1);
    int cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (cnt2 == k2)
        {
            break;
        }
        if (die[i]) continue;
        if (x[i].first * (ll) k2 >= b)
        {
            cnt2++;
            r.push_back(x[i].second);
        }
    }
    assert(cnt2 == k2);
    cout << "Yes\n";
    cout << k1 << ' ' << k2 << '\n';
    for (int c : l)
    {
        cout << c + 1 << ' ';
    }
    cout << '\n';
    for (int c : r)
    {
        cout << c + 1 << ' ';
    }
    cout << '\n';
    exit(0);
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> a >> b;
    x.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i].first;
        x[i].second = i;
    }
    sort(x.rbegin(), x.rend());
    vector <ll> best(n);
    vector <int> gt(n);
    ll s = -1e18;
    int pos = -1;
    for (int i = 0; i < n; i++)
    {
        ll val = x[i].first * (ll) (i + 1);
        if (val > s)
        {
            pos = i + 1;
            s = val;
        }
        best[i] = s;
        gt[i] = pos;
    }
    vector <ll> y(n);
    vector <ll> best1(n);
    vector <int> gt1(n);
    for (int i = 0; i < n; i++)
    {
        ll kek = x[i].first;
        ll k = (i + 1) - div(b, kek);
        y[i] = k;
    }
    s = -1e18;
    pos = -1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (y[i] > s)
        {
            s = y[i];
            pos = i + 1;
        }
        best1[i] = s;
        gt1[i] = pos;
    }
    for (int k = 1; k <= n; k++)
    {
        int l = -1, r = n;
        while (l < r - 1)
        {
            int m = (l + r) / 2;
            if (x[m].first * (ll) k >= a)
            {
                l = m;
            }
            else
            {
                r = m;
            }
        }
        if (l + 1 < k)
        {
            continue;
        }
        int me = l - k;
        if (me != -1)
        {
            if (best[me] >= b)
            {
                print(k, gt[me]);
            }
        }
        int go = l + 1;
        if (go != n)
        {
            if (k <= best1[go])
            {
                print(k, gt1[go] - k);
            }
        }
    }
    cout << "No\n";
}