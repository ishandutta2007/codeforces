#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cmath>
#include <cassert>

using namespace std;
typedef long long ll;
const int MAXN = 1000100;
const int MAXT = 300;
const int HLIM = 300;

int mfac[MAXN];
int tt[MAXN];
int t[MAXN];
int lv[MAXT];
int nfac[MAXT];
int d[MAXT][MAXT];
map <int, int> s;
vector <vector <int> > vv;

vector <int> tfac;
int v (int x)
{
    int cx = x;
    tfac.clear();
    while (x > 1)
    {
        int m = mfac[x];
        int c = 0;
        while (x % m == 0)
        {
            c++;
            x /= m;
        }
        tfac.push_back(c);
    }
    sort (tfac.begin(), tfac.end());
    int tot = 0;
    for (int r : tfac)
        tot = 30 * tot + r;
    tt[cx] = tot;
    return tot;
}

vector <int> decomp (int x)
{
    vector <int> res;
    while (x)
    {
        res.push_back (x % 30);
        x /= 30;
    }
    return res;
}

int gfac (vector <int> &v)
{
    int res = 1;
    for (int cfac : v)
        res *= (cfac + 1);
    return res;
}

int cdist (vector <int> &v1, vector <int> &v2)
{

    int rr = 0;
    for (int i = 0; i < max (v1.size(), v2.size()); i++)
    {
        int l = 0;
        if (i < v1.size()) l = v1[i];
        int r = 0;
        if (i < v2.size()) r = v2[i];
        //cout << v1[i] << " " << v2[i] << " " << rr << endl;
        rr += abs (l - r);
    }
    return rr;
}

int nbest[MAXT], mbest[MAXT];

void buildvv (vector <int> vcur)
{
    vv.push_back(vcur);
    int cprod = 1;
    for (int vval : vcur) cprod *= (vval + 1);
    int hi = HLIM / cprod;
    if (vcur.size())
        hi = min (hi, vcur.back());

    while (hi)
    {
        vcur.push_back(hi);
        buildvv (vcur);
        vcur.pop_back();
        hi--;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    for (int i = 1; i < MAXN; i++)
        mfac[i] = 1;
    for (int i = 2; i < MAXN; i++)
    {
        if (mfac[i] == 1)
        {
            mfac[i] = i;
            for (ll j = i * (ll) i; j < MAXN; j += i)
                mfac[j] = i;
        }
    }

    for (int i = 1; i < MAXN; i++)
    {
        int r = v(i);
        s[r];
    }
    vector <int> empty;
    buildvv (empty);

    int ntype = 0;
    for (auto it = s.begin(); it != s.end(); it++)
    {
        it->second = ntype;
        lv[ntype] = it->first;
        ntype++;
    }

    for (int i = 1; i < MAXN; i++)
        t[i] = s[tt[i]];

    for (int i = 0; i < ntype; i++)
    {
        for (int j = 0; j < MAXT; j++)
            d[i][j] = 1e9;

        vector <int> itype = decomp (lv[i]);
        for (vector <int> &p : vv)
        {
            int g = gfac (p);
            d[i][g] = min (d[i][g], cdist (itype, p));
        }
    }

    int T; cin >> T;
    for (int test = 0; test < T; test++)
    {
        int a, b;
        cin >> a >> b;
        int c1 = t[a], c2 = t[b];

        int res = 1e9;
        for (int i = 0; i < MAXT; i++)
        {
            res = min (res, d[c1][i] + d[c2][i]);
        }
        cout << res << "\n";
    }
}