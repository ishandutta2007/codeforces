#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int MAXN = 9000;
const int M = 24;
 
int N;
int ord[MAXN];
int res[MAXN];
set <int> locs[M];
int nneigh[MAXN];
vector <pair <int, int> > vv;
 
void gogo()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> ord[i];
        ord[i]--;

        nneigh[i] = 0;
    }
 
    for (int i = 0; i < M; i++)
    {
        locs[i].clear();
        locs[i].insert(-MAXN);
        locs[i].insert(MAXN);
    }

    set <int> rv;
    rv.insert(-MAXN);
    rv.insert(MAXN);
    for (int i = 0; i < N; i++)
    {
        auto it = rv.lower_bound(ord[i]);
        auto nit = it;
        nit--;
        if (*nit >= 0) nneigh[*nit]++;
        if (*it < N) nneigh[*it]++;
        rv.insert(ord[i]);
    }
 
    int cbest = -1;
    for (int i = 0; i < N; i++)
    {
        int cur = ord[i];
        vector <int> lo, hi;
        for (int j = 0; j < M; j++)
        {
            auto it = locs[j].lower_bound(cur);
            auto nit = it;
            nit--;
            lo.push_back(*nit);
            hi.push_back(*it);
        }
 
        int bposs = MAXN;
        int blo = -MAXN + 1, bhi = MAXN - 1;
        int pbit = 0;
        for (int j = M - 1; j >= 0; j--)
        {
            if (lo[j] < blo && hi[j] > bhi)
            {
                pbit |= (1 << j);
                bposs = j;
            }
            blo = max (blo, lo[j]);
            bhi = min (bhi, hi[j]);
        }

        for (int j = 0; j < M && ((1 << (j / 2)) <= nneigh[cur]); j++)
            if (pbit & (1 << j))
                bposs = j;
        //bposs = min (bposs, cbest + 1);
 
        res[cur] = bposs;
        locs[bposs].insert(cur);
        cbest = max (cbest, bposs);
    }
 
    for (int i = 0; i < N; i++)
    {
        if (i) cout << " ";
        cout << res[i] + 1;
    }
    cout << "\n";
}
 
int main()
{
    ios_base::sync_with_stdio(0);
 
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        gogo();
    }
}