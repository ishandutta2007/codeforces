#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
typedef long long ll;

int N;
ll S, smod;
vector <pair <ll, ll> > pv; // a - b, s
ll tot;

int main()
{
    ios_base::sync_with_stdio(0);

    tot = 0;
    smod = 0;

    cin >> N >> S;
    for (int i = 0; i < N; i++)
    {
        ll s, a, b;
        cin >> s >> a >> b;

        smod = (smod + s) % S;
        if (s)
        {
            pv.push_back(make_pair(a - b, s));
            tot += b * s;
        }
    }

    if (smod)
        pv.push_back(make_pair(0, S - smod));

    sort(pv.begin(), pv.end());

    ll ccnt = 0, csum = 0;
    for (int cloc = 0; cloc < pv.size(); cloc++)
    {
        ll a = pv[cloc].first, s = pv[cloc].second;
        if (ccnt + s >= S)
        {
            csum += a * (S - ccnt);
            s -= (S - ccnt);
            tot += max (csum, (ll) 0);

            tot += (s / S) * max (S * a, (ll) 0);
            ccnt = s % S;
            csum = ccnt * a;
        }
        else
        {
            ccnt += s;
            csum += s * a;
        }
    }
    cout << tot << "\n";
    return 0;
}