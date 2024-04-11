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
const int MAXN = 610;

int N;
vector <int> edge[MAXN];
bool seen[MAXN];
int mtype[MAXN];
int par[MAXN];

int get_count (vector <int> v)
{
    if (v.size() <= 1) return 0;
    cout << "? " << v.size() << "\n";
    for (int i = 0; i < v.size(); i++)
    {
        if (i) cout << " ";
        cout << v[i] + 1;
    }
    cout << "\n" << flush;

    int r; cin >> r;
    return r;
}

int through (vector <int> v, int cloc)
{
    int l = get_count (v);
    v.push_back(cloc);
    int r = get_count (v);
    v.pop_back();
    return r - l;
}

vector <int> find_all (vector <int> v, int cloc, int ntot)
{
    //cout << "find_all " << cloc << "\n";
    vector <int> res;
    if (!ntot) return res;
    if (ntot == v.size())
    {
        for (int x : v)
            res.push_back(x);
        return res;
    }

    vector <int> vleft, vright;
    for (int i = 0; i < v.size(); i++)
    {
        if (i % 2 == 0)
            vleft.push_back(v[i]);
        else
            vright.push_back(v[i]);
    }

    int tnew = through (vleft, cloc);
    res = find_all (vleft, cloc, tnew);
    vector <int> vres = find_all (vright, cloc, ntot - tnew);
    for (int x : vres)
        res.push_back(x);
    return res;
}

void bflood (int x)
{
    for (int neigh : edge[x])
    {
        if (par[neigh] == -1)
        {
            par[neigh] = x;
            bflood (neigh);
        }
    }
}

void solve_bad (int l, int r)
{
    for (int i = 0; i < MAXN; i++)
        par[i] = -1;
    par[l] = l;

    bflood (l);
    vector <int> res;
    int cloc = r;
    while (cloc != l)
    {
        res.push_back(cloc);
        cloc = par[cloc];
    }
    res.push_back(cloc);

    cout << "N " << res.size() << "\n";
    for (int i = 0; i < res.size(); i++)
    {
        if (i) cout << " ";
        cout << res[i] + 1;
    }
    cout << endl;
}

void wrong (vector <int> v)
{
    int vtot = get_count (v);
    while (true)
    {
        int cloc = v.back();
        v.pop_back();
        if (get_count (v) != vtot)
        {
            for (int i = 0; i < v.size(); i++)
            {
                vector <int> vq;
                vq.push_back(cloc);
                vq.push_back(v[i]);
                if (get_count (vq))
                {
                    solve_bad (cloc, v[i]);
                    return;
                }
            }
        }
    }
}

void dfs (int cloc)
{
    seen[cloc] = true;

    vector <int> vposs;
    for (int i = 0; i < N; i++)
        if (cloc != i && !edge[i].size())
            vposs.push_back(i);

    vector <int> bv = find_all (vposs, cloc, through (vposs, cloc));
    for (int i = 0; i < bv.size(); i++)
    {
        //cout << "add " << cloc << " " << bv[i] << "\n";
        edge[cloc].push_back (bv[i]);
        edge[bv[i]].push_back (cloc);
    }

    for (int i = 0; i < bv.size(); i++)
    {
        int neigh = bv[i];
        if (!seen[neigh])
            dfs (neigh);
    }
}

void flood (int cloc, int ctype)
{
    mtype[cloc] = ctype;
    for (int neigh : edge[cloc])
    {
        if (!mtype[neigh])
            flood (neigh, 3 - ctype);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    dfs (0);

    flood (0, 1);
    vector <int> v1, v2;
    for (int i = 0; i < N; i++)
    {
        if (mtype[i] == 1)
            v1.push_back(i);
        else
            v2.push_back(i);
    }

    if (get_count (v1) > 0)
        wrong (v1);
    else if (get_count (v2) > 0)
        wrong (v2);
    else
    {
        cout << "Y " << v1.size() << "\n";
        for (int i = 0; i < v1.size(); i++)
        {
            if (i) cout << " ";
            cout << v1[i] + 1;
        }
        cout << endl;
    }
}