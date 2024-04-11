#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
typedef long long ll;

int N;
ll ctot;
set <ll> xv, yv;
map <pair <ll, ll>, ll> mmap;

ll gcf (ll a, ll b)
{
    if (b == 0) return a;
    return gcf (b, a % b);
}

int main()
{
    cin >> N;
    ctot = 0;
    for (int i = 0; i < N; i++)
    {
        ll W, H, C;
        cin >> W >> H >> C;
        ctot += C;
        xv.insert(W);
        yv.insert(H);
        mmap[make_pair(W, H)] = C;
    }

    ll xg = *(xv.begin());
    ll yg = *(yv.begin());

    bool bad = false;
    for (set<ll>::iterator it = xv.begin(); it != xv.end(); it++)
    {
        ll cx = *it;
        for (set<ll>::iterator yit = yv.begin(); yit != yv.end(); yit++)
        {
            ll cy = *yit;
            if (!mmap[make_pair(cx, cy)])
            {
                bad = true;
                break;
            }

            ll a = mmap[(make_pair (xg, yg))];
            ll b = mmap[make_pair(xg, cy)];
            ll c = mmap[make_pair(cx, yg)];
            ll d = mmap[make_pair(cx, cy)];

            ll cg = gcf (a, b);
            a /= cg;
            b /= cg;
            cg = gcf (a, c);
            a /= cg;
            c /= cg;
            cg = gcf (b, d);
            b /= cg;
            d /= cg;
            cg = gcf (c, d);
            c /= cg;
            d /= cg;
            if (a + b + c + d != 4)
            {
                bad = true;
                break;
            }

            ctot = gcf (ctot, mmap[make_pair (cx, cy)]);
        }
        if (bad) break;
    }

    if (bad)
    {
        cout << "0\n";
        return 0;
    }

    int x = 0;
    for (ll i = 1; i * i <= ctot; i++)
    {
        if (ctot % i == 0)
        {
            x++;
            if (i * i != ctot)
                x++;
        }
    }
    cout << x << "\n";
}