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
const int MAXN = 300100;

int N;
ll A[2][MAXN];
ll ps[2][MAXN];
ll pps[2][MAXN];

ll roller (int i, int j)
{
    // sum N-1, 2 * N-2, ... j
    return pps[i][N] - pps[i][j] - ps[i][j] * (N - j);
}

ll ns (int i, int j)
{
    // sum j...N-1
    return ps[i][N] - ps[i][j];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < N; j++)
            cin >> A[i][j];
    for (int i = 0; i < 2; i++)
    {
        ps[i][0] = 0;
        for (int j = 0; j < N; j++)
            ps[i][j+1] = ps[i][j] + A[i][j];
        pps[i][0] = 0;
        for (int j = 0; j < N; j++)
        {
            pps[i][j+1] = pps[i][j] + ps[i][j+1];
        }
    }

    //for (int i = 0; i <= N; i++)
    //    cout << roller (0, i) << "\n";

    ll nbest = 0;
    ll ctot = 0;
    for (int i = 0; i <= N; i++)
    {
        int ci = i % 2;
        ll nv = ctot + roller (ci^1, i) + (i + N - 1) * ns (ci^1, i) + (i + N) * ns(ci, i) - roller(ci, i);
        //cout << i << " " << nv << "\n";
        nbest = max (nbest, nv);

        if (i < N)
        {
            ctot += A[i%2][i] * (2 * i) + A[(i+1)%2][i] * (2 * i + 1);
        }
    }
    cout << nbest << "\n";
}