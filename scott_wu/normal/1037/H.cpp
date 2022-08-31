#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>

using namespace std;
typedef long long ll;
const int MAXN = 100100;
const int MAXQ = 200100;
const int P = (1 << 17);

int N, Q;
string S;
int sval[MAXN];

// suffix array
int suford[MAXN];
int sufval[MAXN];
pair <pair <int, int>, int> ssort[MAXN];

void suff_array()
{
    if (N == 1)
    {
        sufval[0] = suford[0] = 0;
        return;
    }
    int cpow = 1;
    for (int i = 0; i < N; i++)
        sufval[i] = sval[i];

    while (cpow < N)
    {
        for (int i = 0; i < N; i++)
        {
            ssort[i].second = i;
            ssort[i].first.first = sufval[i];
            if (i + cpow < N)
            {
                ssort[i].first.second = sufval[i+cpow];
            }
            else
                ssort[i].first.second = -1;
        }

        sort (ssort, ssort + N);
        int nc = 0;
        for (int i = 0; i < N; i++)
        {
            if (i > 0 && ssort[i].first != ssort[i-1].first)
                nc++;
            sufval[ssort[i].second] = nc;
        }

        cpow *= 2;
    }
    for (int i = 0; i < N; i++)
        suford[sufval[i]] = i;
}

// find intervals
string qs[MAXQ];
vector <int> ploc[MAXQ];
vector <int> pans[MAXQ];

int lsearch (int lo, int hi, int c, int l)
{
    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        if (sval[suford[mid] + l] < c)
            lo = mid + 1;
        else
            hi = mid;
    }
    return lo;
}

// sweep intervals and segtree solve
vector <pair <pair <int, int>, pair <int, pair <int, int> > > > v[MAXN];

int seg[2*P];

int find_min (int cloc, int rlo, int rhi, int lo, int hi)
{
    if (rhi < lo || hi < rlo)
        return 1e9;
    if (lo <= rlo && rhi <= hi)
        return seg[cloc];
    //cout << cloc << " " << lo << " " << hi << "\n";
    int rmid = (rlo + rhi) / 2;
    return min (find_min (2 * cloc, rlo, rmid, lo, hi),
                find_min (2 * cloc + 1, rmid + 1, rhi, lo, hi));
}

void upd (int cloc, int val)
{
    cloc += P;
    while (cloc)
    {
        seg[cloc] = min (seg[cloc], val);
        cloc /= 2;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> S;
    N = S.length();
    for (int i = 0; i < N; i++)
    {
        sval[i] = S[i] - 'a';
    }
    sval[N] = -1;

    for (int i = 0; i < N; i++)
    {
        suford[i] = i;
    }
    suff_array();
    //for (int i = 0; i < N; i++)
    //    cout << suford[i];

    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        string cs;
        cin >> cs;

        int clo = 0, chi = N - 1;
        for (int j = 0; j <= cs.length() && j + l <= r; j++)
        {
            int cj = 0;
            if (j < cs.length())
                cj = cs[j] - 'a' + 1;
            int mlast = chi + 1, mnext = 0;
            mnext = lsearch (clo, mlast, cj, j);
            //cout << j << " " << k << " " << p.first << " " << p.second << "\n";
            if (mnext < mlast)
            {
                int llo = l, lhi = r - j;
                //cout << llo << " " << lhi << " " << p.first << " " << p.second << "\n";

                ploc[i].push_back(j);
                pans[i].push_back(-1);
                v[mnext].push_back(make_pair (make_pair (llo, lhi), 
                    make_pair (mlast - 1, make_pair (i, ploc[i].size() - 1))));
            }
            mlast = mnext;

            if (j < cs.length())
            {
                mnext = lsearch (clo, mlast, cj - 1, j);
                if (mnext >= mlast) break;
                clo = mnext;
                chi = mlast - 1;
            }
        }
        qs[i] = cs;
    }

    for (int i = 0; i < 2 * P; i++)
        seg[i] = MAXN;
    for (int i = N - 1; i >= 0; i--)
    {
        upd (suford[i], i);
        for (int j = 0; j < v[i].size(); j++)
        {
            int lo = v[i][j].first.first, hi = v[i][j].first.second;
            int rj = v[i][j].second.first;
            int p1 = v[i][j].second.second.first, p2 = v[i][j].second.second.second;
            //cout << i << " " << rj << " " << lo << " " << hi << " " << p1 << " " << p2 << " " << ploc[p1][p2] << endl;
            int sloc = find_min(1, 0, P - 1, lo, hi);
            //cout << sloc << endl;
            if (sloc > rj) continue;
            pans[p1][p2] = sval[suford[sloc]+ploc[p1][p2]];
        }
    }

    for (int i = 0; i < Q; i++)
    {
        bool found = false;
        for (int j = (int) pans[i].size() - 1; j >= 0; j--)
        {
            if (pans[i][j] != -1)
            {
                for (int k = 0; k < ploc[i][j]; k++)
                    cout << qs[i][k];
                cout << (char) ('a' + pans[i][j]);
                cout << "\n";
                found = true;
                break;
            }
        }
        if (!found)
            cout << "-1\n";
    }
}