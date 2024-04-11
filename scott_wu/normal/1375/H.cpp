#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 4200;
const int MAXP = 2 * MAXN + 100;
const int MAXQ = (1 << 16) + 100;
const int MAXA = 2.5e6;

int N, Q;
int arr[MAXN];
int rloc[MAXN];
pair <int, int> rng[MAXQ];

int P, nd;
int rlo[MAXP], rhi[MAXP];
int nv[MAXN][MAXN], pv[MAXN][MAXN];
map <int, int> mm[MAXP];

int A;
int p1[MAXA], p2[MAXA];
int aloc[MAXQ];

int proc (int a, int b)
{
    return a * MAXP + b;
}

int gsolve (int pp, int lo, int hi);

int qsolve (int pp, int lo, int hi)
{
    int r1 = pp * 2, r2 = pp * 2 + 1;
    int g1 = gsolve (r1, lo, hi), g2 = gsolve (r2, lo, hi);
    if (g1 == -1) return g2;
    if (g2 == -1) return g1;
    p1[A] = g1;
    p2[A] = g2;
    A++;
    return A - 1;
}

int gsolve (int pp, int lo, int hi)
{
    // solve all elems of range pp from lo to hi
    if (pp >= P)
    {
        if (pp - P >= N) return -1;
        int a = rloc[pp-P];
        if (a >= lo && a <= hi)
            return a;
        else
            return -1;
    }
    if (nv[pp][lo] > hi) return -1;
    //cout << pp << " " << lo << " " << hi << "\n";
    lo = nv[pp][lo];
    hi = pv[pp][hi];
    int pl = proc (lo, hi);
    if (mm[pp].find (pl) != mm[pp].end())
        return mm[pp][pl];

    int res = qsolve (pp, lo, hi);
    //cout << pp << " " << lo << " " << hi << " " << res << "\n";
    mm[pp][pl] = res;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N >> Q;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        arr[i]--;
        rloc[arr[i]] = i;
    }
    for (int i = 0; i < Q; i++)
    {
        cin >> rng[i].first >> rng[i].second;
        rng[i].first--;
        rng[i].second--;
    }

    P = 1;
    nd = 0;
    while (P < N)
    {
        P *= 2;
        nd++;
    }

    rlo[1] = 0;
    rhi[1] = P - 1;
    for (int i = 2; i < 2 * P; i++)
    {
        int md = (rlo[i/2] + rhi[i/2]) / 2;
        if (i % 2 == 0)
        {
            rlo[i] = rlo[i/2];
            rhi[i] = md;
        }
        else
        {
            rlo[i] = md + 1;
            rhi[i] = rhi[i/2];
        }
    }

    for (int i = 1; i < P; i++)
    {
        //cout << i << " " << rlo[i] << " " << rhi[i] << "\n";
        nv[i][N] = N;
        for (int j = N - 1; j >= 0; j--)
        {
            if (arr[j] >= rlo[i] && arr[j] <= rhi[i])
                nv[i][j] = j;
            else
                nv[i][j] = nv[i][j+1];
        }

        if (arr[0] >= rlo[i] && arr[0] <= rhi[i])
            pv[i][0] = 0;
        else
            pv[i][0] = -1;
        for (int j = 1; j < N; j++)
        {
            if (arr[j] >= rlo[i] && arr[j] <= rhi[i])
                pv[i][j] = j;
            else
                pv[i][j] = pv[i][j-1];
        }
    }

    for (int i = 0; i < N; i++)
    {
        mm[arr[i]+P][proc (i, i)] = i;
    }

    A = N;
    for (int i = 0; i < Q; i++)
    {
        aloc[i] = gsolve (1, rng[i].first, rng[i].second);
    }

    cout << A << "\n";
    for (int i = N; i < A; i++)
    {
        cout << p1[i] + 1 << " " << p2[i] + 1 << "\n";
    }
    for (int i = 0; i < Q; i++)
    {
        if (i) cout << " ";
        cout << aloc[i] + 1;
    }
    cout << "\n";
}