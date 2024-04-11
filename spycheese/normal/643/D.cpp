#include <bits/stdc++.h>

#ifndef LOCAL
#define cerr dolor_sit_amet
#endif

#define mp make_pair
#define sz(x) ((int)((x).size()))

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int , int > ipair;
typedef pair < ll , ll > lpair;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = numeric_limits<double>::infinity();
const ll MOD = 1000000007;
const double EPS = 1e-9;
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};

// ========================================================================= //

const int N = 100179;

multiset < ll > mmx;
struct Page
{
    ll t;
    int f;
    set < pair < ll , int > > e;
    ll od;
    ll ead;

    void setEad()
    {
        if (!e.empty())
        {
            mmx.erase(mmx.find(e.begin()->first + ead));
            mmx.erase(mmx.find(e.rbegin()->first + ead));
        }
        ead = t / (sz(e) + 2);
        if (!e.empty())
        {
            mmx.insert(e.begin()->first + ead);
            mmx.insert(e.rbegin()->first + ead);
        }
    }

    void setOd(ll nod);
} p[N];
int n;

void Page::setOd(ll nod)
{
    if (!p[f].e.empty())
    {
        mmx.erase(mmx.find(p[f].e.begin()->first + p[f].ead));
        mmx.erase(mmx.find(p[f].e.rbegin()->first + p[f].ead));
    }
    p[f].e.erase({od, this - p});
    p[f].e.insert({od = nod, this - p});
    if (!p[f].e.empty())
    {
        mmx.insert(p[f].e.begin()->first + p[f].ead);
        mmx.insert(p[f].e.rbegin()->first + p[f].ead);
    }
}

int main()
{
    ios::sync_with_stdio(false);

    int q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i)
        cin >> p[i].t;
    for (int i = 0; i < n; ++i)
    {
        cin >> p[i].f;
        --p[i].f;
        p[p[i].f].e.emplace(0, i);
    }
    for (int i = 0; i < n; ++i)
    {
        int k = sz(p[i].e);
        p[i].od += p[i].t - p[i].t / (k + 2) * (k + 1);
        p[p[i].f].od += (p[i].ead = p[i].t / (k + 2));
        p[i].e.clear();
    }
    for (int i = 0; i < n; ++i)
        p[p[i].f].e.emplace(p[i].od, i);
    for (int i = 0; i < n; ++i)
        if (!p[i].e.empty())
        {
            mmx.insert(p[i].e.begin()->first + p[i].ead);
            mmx.insert(p[i].e.rbegin()->first + p[i].ead);
        }

    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int v, f;
            cin >> v >> f;
            --v;
            --f;
            int cf = p[v].f;
            int k = sz(p[cf].e);
            ll t = p[cf].t;
            if (!p[cf].e.empty())
            {
                mmx.erase(mmx.find(p[cf].e.begin()->first + p[cf].ead));
                mmx.erase(mmx.find(p[cf].e.rbegin()->first + p[cf].ead));
            }
            p[cf].e.erase({p[v].od, v});
            if (!p[cf].e.empty())
            {
                mmx.insert(p[cf].e.begin()->first + p[cf].ead);
                mmx.insert(p[cf].e.rbegin()->first + p[cf].ead);
            }
            p[cf].setEad();
            p[cf].setOd(p[cf].od - (t-t/(k+2)*(k+1)) + (t-t/(k+1)*k) - p[v].ead);
            p[p[cf].f].setOd(p[p[cf].f].od - t/(k+2) + t/(k+1));

            p[v].f = f;
            k = sz(p[f].e) + 1;
            t = p[f].t;
            if (!p[f].e.empty())
            {
                mmx.erase(mmx.find(p[f].e.begin()->first + p[f].ead));
                mmx.erase(mmx.find(p[f].e.rbegin()->first + p[f].ead));
            }
            p[f].e.insert({p[v].od, v});
            if (!p[f].e.empty())
            {
                mmx.insert(p[f].e.begin()->first + p[f].ead);
                mmx.insert(p[f].e.rbegin()->first + p[f].ead);
            }
            p[f].setEad();
            p[f].setOd(p[f].od + (t-t/(k+2)*(k+1)) - (t-t/(k+1)*k) + p[v].ead);
            p[p[f].f].setOd(p[p[f].f].od + t/(k+2) - t/(k+1));
        } else if (type == 2)
        {
            int v;
            cin >> v;
            --v;
            cout << p[v].od + p[p[v].f].ead << "\n";
        } else
            cout << *mmx.begin() << " " << *mmx.rbegin() << "\n";
    }

    return 0;
}