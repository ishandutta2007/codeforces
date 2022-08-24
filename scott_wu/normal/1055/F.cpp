#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;
typedef long long ll;
const int MAXN = 1000100;

int N;
ll K;
ll arr[MAXN], anew[MAXN], tcur[MAXN], tnew[MAXN];

int main()
{
    scanf ("%d %I64d", &N, &K);
    arr[0] = 0;
    for (int i = 1; i < N; i++)
    {
        int p;
        ll w;
        scanf ("%d %I64d", &p, &w);
        p--;
        arr[i] = arr[p] ^ w;
    }

    sort (arr, arr + N);
    for (int i = 0; i < N; i++)
        anew[i] = arr[i];

    ll ans = 0;
    for (int i = 61; i >= 0; i--)
    {
        for (int j = 0; j < N; j++)
        {
            tcur[j] = (arr[j] >> i);
            tnew[j] = (anew[j] >> i);
        }

        ll pp = 0;
        int lloc = 0, rloc = 0;
        while (lloc < N)
        {
            ll cv = tcur[lloc];
            while (rloc < N && tnew[rloc] < cv)
                rloc++;

            ll nl = 0, nr = 0;
            while (lloc < N && tcur[lloc] == cv)
            {
                lloc++;
                nl++;
            }
            while (rloc < N && tnew[rloc] == cv)
            {
                rloc++;
                nr++;
            }

            pp += nl * nr;
        }

        if (pp < K)
        {
            ans += (1LL << i);
            K -= pp;
            for (int j = 0; j < N; j++)
                anew[j] ^= (1LL << i);
            for (int j = 0; j < N - 1; j++)
            {
                if (anew[j] > anew[j+1])
                {
                    int cj = j, ej = j + 1;
                    while (cj && anew[cj-1] > anew[j+1])
                        cj--;
                    while (ej < N - 1 && anew[ej+1] < anew[j])
                        ej++;
                    reverse (anew + cj, anew + j + 1);
                    reverse (anew + j + 1, anew + ej + 1);
                    reverse (anew + cj, anew + ej + 1);
                }
            }
        }
    }
    cout << ans << "\n";
}