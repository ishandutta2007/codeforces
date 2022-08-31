#include <iostream>
#include <iomanip>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <string>
#include <ctime>

using namespace std;
typedef long long ll;
const int MAXD = 60e6;
const int MAXN = 100100;
const int BLOCK = 100;

int N, Q, W;
int X[MAXN];
pair <int, int> query[MAXN];
int ans[MAXN];
int vchange[MAXD];
int nind[MAXN];
int blo[MAXN], bhi[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> N >> W >> Q;
    for (int i = 0; i < N; i++)
    {
        cin >> X[i];
    }
    for (int i = 0; i < Q; i++)
    {
        cin >> query[i].first;
        query[i].first = W - query[i].first;
        query[i].second = i;
    }

    for (int i = 0; i < N; i++)
    {
        blo[i] = bhi[i] = X[i];
        for (int j = i; j < i + BLOCK && j < N; j++)
        {
            blo[i] = min (blo[i], X[j]);
            bhi[i] = max (bhi[i], X[j]);
        }
    }
    sort (query, query + Q);

    int narr = 0;
    for (int cloc = 0; cloc < N; cloc++)
    {
        nind[cloc] = narr;
        int cval = 0, mnext = 2e9;
        int end = min (cloc + BLOCK, N);
        while (true)
        {
            int jlo = 1e9, jhi = 0;
            int nlast = -1, nuse = 0;
            mnext = 2e9;
            for (int i = cloc; i < end; i++)
            {
                if (X[i] < jlo)
                    jlo = X[i];
                if (X[i] > jhi)
                    jhi = X[i];
                if (jhi - jlo > cval)
                {
                    mnext = min (mnext, jhi - jlo);
                    nlast = i;
                    nuse++;
                    jlo = jhi = X[i];
                }
            }

            vchange[narr++] = mnext;
            vchange[narr++] = nuse;
            vchange[narr++] = nlast;
            if (nlast == -1) break;
            cval = mnext;
        }
    }

    for (int i = 0; i < Q; i++)
    {
        int cc = query[i].first;
        int cloc = 0;
        int res = 0;
        while (cloc < N)
        {
            int &n = nind[cloc];
            while (vchange[n] <= cc)
                n += 3;
            if (vchange[n+2] == -1)
            {
                res++;
                int jlo = blo[cloc], jhi = bhi[cloc];
                cloc += BLOCK;
                while (cloc < N)
                {
                    if (max(jhi, bhi[cloc]) - min (jlo, blo[cloc]) <= cc)
                    {
                        jhi = max (jhi, bhi[cloc]);
                        jlo = min (jlo, blo[cloc]);
                        cloc += BLOCK;
                    }
                    else
                        break;
                }
                while (cloc < N)
                {
                    jlo = min (jlo, X[cloc]);
                    jhi = max (jhi, X[cloc]);
                    if (jhi - jlo > cc)
                        break;
                    cloc++;
                }
            }
            else
            {
                res += vchange[n+1];
                cloc = vchange[n+2];
            }
        }
        ans[query[i].second] = res - 1;
    }

    for (int i = 0; i < Q; i++)
        cout << ans[i] << "\n";
}