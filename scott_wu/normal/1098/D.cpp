#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXQ = 500100;
const int P = (1 << 19);
const int MAXP = 2 * P + 100;

int Q;
char ct[MAXQ];
int cv[MAXQ];
map <ll, int> mm;
ll seg[MAXP];

void upd (int cloc, int nadd)
{
    cloc += P;
    while (cloc)
    {
        seg[cloc] += nadd;
        cloc /= 2;
    }
}

ll rsum (int cloc)
{
    cloc += P;
    ll ans = 0;
    while (cloc > 1)
    {
        if (cloc & 1)
            ans += seg[cloc-1];
        cloc /= 2;
    }
    return ans;
}

multiset <ll> s;
map <ll, ll> specs;

int gbad()
{
    int ans = 0;
    for (pair <ll, ll> p : specs)
    {
        ll lo = p.first, goal = p.second;
        ll csum = rsum (mm[lo] + 1);
        //cout << lo << " " << csum << " " << goal << "\n";
        if (csum * 2 < goal)
            ans++;
    }
    return ans;
}

int main()
{
    s.insert (0);
    s.insert (1e18);
    specs[0] = 1e18;

    mm[0];
    scanf ("%d", &Q);
    for (int i = 0; i < Q; i++)
    {
        scanf (" %c %d", &ct[i], &cv[i]);
        mm[cv[i]];
    }
    int ms = 0;
    for (auto it = mm.begin(); it != mm.end(); it++)
        it->second = ms++;

    int N = 0;
    for (int i = 0; i < Q; i++)
    {
        char c = ct[i];
        ll x = cv[i];
        if (c == '+')
        {
            N++;
            if (s.find(x) == s.end())
            {
                auto it = s.upper_bound(x);
                ll hi = *it;
                it--;
                ll lo = *it;
                specs.erase(lo);
                if (x >= 2 * lo)
                    specs[lo] = x;
                if (hi >= 2 * x)
                    specs[x] = hi;
            }
            s.insert(x);
            int cloc = mm[x];
            upd (cloc, x);
        }
        else
        {
            N--;
            s.erase(s.find(x));
            if (s.find(x) == s.end())
            {
                auto it = s.upper_bound(x);
                ll hi = *it;
                it--;
                ll lo = *it;
                specs.erase(lo);
                specs.erase(x);
                if (hi >= 2 * lo)
                    specs[lo] = hi;
            }

            int cloc = mm[x];
            upd (cloc, -x);
        }

        printf ("%d\n", N + 1 - gbad());
    }
}