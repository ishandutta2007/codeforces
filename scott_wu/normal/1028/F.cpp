#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <set>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int Q, NP;
map <ll, int> mm;
vector <pair <int, int> > v[MAXN];
map <pair <int, int>, int> score;

int gcd (int x, int y)
{
    if (y == 0) return x;
    return gcd (y, x % y);
}

pair <int, int> reduce (pair <int, int> p)
{
    int g = gcd (p.first, p.second);
    return make_pair(p.first / g, p.second / g);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> Q;
    NP = 0;
    int ntot = 0;
    for (int q = 0; q < Q; q++)
    {
        int a, x, y;
        cin >> a >> x >> y;

        if (a == 1)
        {
            ntot++;
            ll d = x * (ll) x + y * (ll) y;
            if (mm.find(d) == mm.end())
                mm[d] = NP++;

            int vloc = mm[d];
            int cc = -1;
            for (int i = 0; i < v[vloc].size(); i++)
            {
                int xx = v[vloc][i].first, yy = v[vloc][i].second;
                if (x == xx && y == yy)
                    cc = i;
                else
                    score[reduce (make_pair (x + xx, y + yy))] += 2;
            }
            score[reduce (make_pair (x, y))] += 1;
            v[vloc].push_back(make_pair(x, y));
        }
        if (a == 2)
        {
            ntot--;
            ll d = x * (ll) x + y * (ll) y;
            if (mm.find(d) == mm.end())
                mm[d] = NP++;

            int vloc = mm[d];
            int cc = -1;
            for (int i = 0; i < v[vloc].size(); i++)
            {
                int xx = v[vloc][i].first, yy = v[vloc][i].second;
                if (x == xx && y == yy)
                    cc = i;
                else
                    score[reduce (make_pair (x + xx, y + yy))] -= 2;
            }
            score[reduce (make_pair (x, y))] -= 1;
            v[vloc].erase(v[vloc].begin()+cc);
        }
        if (a == 3)
        {
            pair <int, int> rp = reduce (make_pair (x, y));
            //cout << ntot << " " << score[rp] << "\n";
            cout << ntot - score[rp] << "\n";
        }

    }
}