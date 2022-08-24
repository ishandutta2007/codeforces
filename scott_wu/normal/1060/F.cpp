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
typedef long double ld;
const int MAXN = 55;

int N;
vector <int> edge[MAXN];

ld pascal[MAXN][MAXN];

ld C (int x, int y)
{
    return pascal[x][y];
}

ld eval (vector <ld> v)
{
    return v[(int) v.size() - 1];
}

vector <ld> append (vector <ld> v)
{
    vector <ld> res;
    for (int i = 0; i <= v.size(); i++)
        res.push_back(0.0);

    int nsize = v.size();

    for (int i = 0; i <= nsize; i++)
    {
        for (int j = 0; j < i; j++)
        {
            res[i] += v[j] / nsize / 2.;
        }
        if (i < nsize)
            res[i] += v[i] * (nsize - i) / nsize;
    }
    return res;
}

vector <ld> combine (vector <ld> l, vector <ld> r)
{
    /*cout << "combine\n";
    for (int i = 0; i < l.size(); i++) cout << l[i] << " ";
    cout << "\n";
    for (int i = 0; i < r.size(); i++) cout << r[i] << " ";
    cout << "\n";*/

    vector <ld> res;
    int ntot = l.size() + r.size() - 1;
    for (int i = 0; i < ntot; i++)
        res.push_back(0.0);

    for (int i = 0; i < l.size(); i++)
        for (int j = 0; j < r.size(); j++)
        {
            res[i+j] += l[i] * r[j] * C(i+j, i) * C(ntot - 1 - i - j, l.size() - i - 1) / C (ntot - 1, l.size() - 1);
        }
    //for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
    //    cout << "\n";
    return res;
}

vector <ld> flood (int cloc, int last)
{
    vector <ld> v;
    v.push_back(1.0);
    for (int neigh : edge[cloc])
    {
        if (neigh == last) continue;
        vector <ld> nv = flood (neigh, cloc);
        nv = append (nv);
        /*cout << "neigh " << neigh << "\n";
        for (int i = 0; i < nv.size(); i++) cout << nv[i] << " ";
        cout << "\n";*/
        v = combine (v, nv);
    }
    /*cout << "cloc " << cloc << "\n";
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << "\n";*/
    return v;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    pascal[0][0] = 1;
    for (int i = 1; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
        {
            pascal[i][j] = pascal[i-1][j];
            if (j) pascal[i][j] += pascal[i-1][j-1];
        }

    cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }

    cout << fixed << setprecision(8);
    for (int i = 0; i < N; i++)
    {
        vector <ld> v = flood (i, -1);
        cout << eval (v) << "\n";
    }

}