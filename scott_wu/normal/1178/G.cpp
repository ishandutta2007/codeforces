#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <cassert>
 
using namespace std;
typedef long long ll;
typedef long double ld;
const int MAXN = 401000;
const int BSIZE = 200; // 200 buckets of 1000
const int NBUCK = 200000 / BSIZE + 20;

int N, Q;
int par[MAXN];
int ssize[MAXN];
int sloc[MAXN];
vector <int> child[MAXN];
int nord;
int ord[MAXN];
ll a[MAXN], b[MAXN];
pair <ll, ll> pp[MAXN];

int M;
ll nadd[NBUCK];
int gind[NBUCK];
vector <int> qloc[NBUCK];
vector <int> bloc[NBUCK];

inline bool cmp (int x, int y)
{
    return b[x] < b[y];
}

void flood (int cloc)
{
    ord[nord] = cloc;
    sloc[cloc] = nord;
    nord++;
    for (int x : child[cloc])
        flood (x);
}

ll ginter (int i, int j)
{
    return (a[i] * b[i] - a[j] * b[j]) / (b[j] - b[i]);
}

void gen (int ind) // create hull for this bucket
{
    qloc[ind].clear();
    for (int i = ind * BSIZE; i < min (N, (ind + 1) * BSIZE); i++)
    {
        a[i] += nadd[ind];
        a[i+N] += nadd[ind];
    }
    nadd[ind] = 0;

    for (int i : bloc[ind])
    {
        qloc[ind].push_back(i);
        int q = qloc[ind].size();
        if (q >= 2)
        {
            int j = qloc[ind][q-2];
            if (b[j] == b[i])
            {
                if (a[j] * b[j] > a[i] * b[i])
                    qloc[ind].pop_back();
                else
                {
                    qloc[ind][q-2] = i;
                    qloc[ind].pop_back();
                }
                q--;
            }
        }
        while (q >= 3)
        {
            int x = qloc[ind][q-3], y = qloc[ind][q-2], z = qloc[ind][q-1];
            if (ginter (x, y) >= ginter (y, z))
            {
                qloc[ind][q-2] = z;
                qloc[ind].pop_back();
                q--;
            }
            else
                break;
        }
    }
    gind[ind] = 0;
}

ll csolve (int ind)
{
    int x = qloc[ind][gind[ind]];
    ll lv = (a[x] + nadd[ind]) * b[x];
    while (gind[ind] + 1 < qloc[ind].size())
    {
        int y = qloc[ind][gind[ind] + 1];
        ll nv = (a[y] + nadd[ind]) * b[y];
        if (nv >= lv)
        {
            gind[ind]++;
            lv = nv;
        }
        else
            break;
    }
    return lv;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N >> Q;
    for (int i = 1; i < N; i++)
    {
        cin >> par[i];
        par[i]--;
        child[par[i]].push_back(i);
    }
    for (int i = 0; i < N; i++)
        ssize[i] = 1;
    for (int i = N - 1; i >= 1; i--)
        ssize[par[i]] += ssize[i];

    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        if (i) a[i] += a[par[i]];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> b[i];
        if (i) b[i] += b[par[i]];
    }

    nord = 0;
    flood (0);

    for (int i = 0; i < N; i++)
        pp[i] = make_pair (a[i], b[i]);
    for (int i = 0; i < N; i++)
    {
        a[i] = pp[ord[i]].first;
        b[i] = pp[ord[i]].second;
        a[i+N] = a[i];
        b[i+N] = -b[i];
    }

    M = (N - 1) / BSIZE + 1;
    for (int i = 0; i < M; i++)
    {
        for (int j = i * BSIZE; j < i * BSIZE + BSIZE; j++)
            if (j < N)
            {
                bloc[i].push_back(j);
                bloc[i].push_back(j+N);
            }
        sort (bloc[i].begin(), bloc[i].end(), cmp);
        nadd[i] = 0;
        gen (i);
    }

    for (int q = 0; q < Q; q++)
    {
        int c; cin >> c;
        if (c == 1)
        {
            int v, x;
            cin >> v >> x;
            v--;
            int sstart = sloc[v], send = sloc[v] + ssize[v];
            int bstart = sstart / BSIZE, bend = send / BSIZE;
            if (bstart != bend)
            {
                for (int i = bstart + 1; i < bend; i++)
                    nadd[i] += x;
                for (int i = sstart; i < (bstart + 1) * BSIZE; i++)
                {
                    a[i] += x;
                    a[i+N] += x;
                }
                gen (bstart);
                for (int i = bend * BSIZE; i < send; i++)
                {
                    a[i] += x;
                    a[i+N] += x;
                }
                gen (bend);
            }
            else
            {
                for (int i = sstart; i < send; i++)
                {
                    a[i] += x;
                    a[i+N] += x;
                }
                gen (bend);                
            }
        }
        else
        {
            int v; cin >> v;
            v--;
            ll ans = 0;
            int sstart = sloc[v], send = sloc[v] + ssize[v];
            int bstart = sstart / BSIZE, bend = send / BSIZE;

            if (bstart != bend)
            {
                for (int i = bstart + 1; i < bend; i++)
                    ans = max (ans, csolve (i));
                for (int i = sstart; i < (bstart + 1) * BSIZE; i++)
                    ans = max (ans, abs ((a[i] + nadd[bstart]) * b[i]));
                for (int i = bend * BSIZE; i < send; i++)
                    ans = max (ans, abs ((a[i] + nadd[bend]) * b[i]));
            }
            else
            {
                for (int i = sstart; i < send; i++)
                    ans = max (ans, abs ((a[i] + nadd[bend]) * b[i]));
            }

            cout << ans << "\n";
        }
    }
}