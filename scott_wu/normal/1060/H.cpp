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
const int MAXN = 12;

int P, D;
int A, B, ONE;
int TOT;
int cloc;

void put_add (int l, int r, int e)
{
    cout << "+ " << l << " " << r << " " << e << "\n";
}

void put_pow (int s, int e)
{
    cout << "^ " << s << " " << e << "\n";
}

int mmake (vector <int> v)
{
    // D-th power of sum of v[i]
    int res_loc = cloc++;
    if (v.size() == 1)
    {
        put_pow (v[0], res_loc);
        return res_loc;
    }
    put_add(v[0], v[1], res_loc);
    for (int i = 2; i < v.size(); i++)
        put_add(v[i], res_loc, res_loc);
    put_pow(res_loc, res_loc);
    return res_loc;
}

int mmult (int ncur, int val)
{
    if (val == 1) return ncur;
    int nloc = cloc++;
    put_add(ncur, ncur, nloc);
    int gloc = mmult (nloc, val / 2);
    if (val % 2)
        put_add(ncur, gloc, gloc);
    return gloc;
}

ll inv (ll x)
{
    ll cpow = x, b = P - 2;
    ll cres = 1;
    while (b)
    {
        if (b & 1)
        {
            cres = (cres * cpow) % P;
        }
        cpow = (cpow * cpow) % P;
        b /= 2;
    }
    return cres;
}

int pascal[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    A = 1;
    B = 2;
    ONE = 3;
    TOT = -1;

    cin >> D >> P;
    pascal[0][0] = 1;
    for (int i = 1; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
        {
            pascal[i][j] = pascal[i-1][j];
            if (j) pascal[i][j] += pascal[i-1][j-1];
        }

    cloc = 10;
    for (int ac = 0; ac <= 1; ac++)
    {
        for (int bc = 0; bc <= 1; bc++)
        {
            for (int oc = 0; oc <= D - 2; oc++)
            {
                if (ac + bc + oc == 0) continue;
                vector <int> vloc;
                for (int i = 0; i < ac; i++)
                    vloc.push_back(A);
                for (int i = 0; i < bc; i++)
                    vloc.push_back(B);
                for (int i = 0; i < oc; i++)
                    vloc.push_back(ONE);
                int cg = mmake (vloc);

                ll cc = 1;
                if ((ac + bc + oc + D) % 2 != 0)
                    cc = -cc;
                cc *= pascal[D-2][oc];
                cc = (cc % P + P) % P;

                int ng = mmult (cg, cc);
                if (TOT == -1)
                    TOT = ng;
                else
                    put_add (ng, TOT, TOT);
            }
        }
    }
    ll cc = 1;
    for (int i = 1; i <= D; i++)
        cc *= i;
    cc %= P;
    cc = inv (cc);
    int nres = mmult (TOT, cc);
    cout << "f " << nres << "\n";
}