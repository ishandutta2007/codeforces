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
const int MAXS = 10100;
const int MAXN = 110;

int N;
int arr[MAXN];
int M;
int val[MAXN], ncnt[MAXN];
int nways[MAXN][MAXS];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort (arr, arr + N);

    M = 0;
    int cloc = 0;
    while (cloc < N)
    {
        int cval = arr[cloc];
        int oloc = cloc;
        while (cloc < N && arr[cloc] == cval)
            cloc++;
        val[M] = cval;
        ncnt[M] = cloc - oloc;
        M++;
    }

    for (int i = 0; i < MAXS; i++)
        for (int j = 0; j < MAXN; j++)
            nways[j][i] = 0;
    nways[0][0] = 1;

    for (int i = 0; i < M; i++)
    {
        for (int j = MAXS; j >= 0; j--)
        {
            for (int cc = 0; cc <= N; cc++)
            {
                if (nways[cc][j])
                {
                    for (int k = 1; k <= ncnt[i]; k++)
                    {
                        int nj = j + k * val[i];
                        nways[cc+k][nj] += nways[cc][j];
                        if (nways[cc+k][nj] > 2) nways[cc+k][nj] = 2;
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < M; i++)
    {
        for (int j = 1; j <= ncnt[i]; j++)
        {
            int nj = j * val[i];
            if (nways[j][nj] == 1)
                ans = max (ans, j);
        }
    }
    if (M == 2)
    {
        if (nways[ncnt[0]][ncnt[0]*val[0]] == 1)
            ans = max (ans, N);
    }
    cout << ans << "\n";
}