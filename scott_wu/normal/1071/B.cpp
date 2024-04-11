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
const int MAXN = 2100;

int N, K;
string s[MAXN];
int bv[MAXN][MAXN]; // max a's
bool work[MAXN];
bool nwork[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> s[i];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            int cloc = 0;
            if (s[i][j] == 'a') cloc = 1;
            bv[i][j] = cloc;
            if (i)
                bv[i][j] = max (bv[i][j], cloc + bv[i-1][j]);
            if (j)
                bv[i][j] = max (bv[i][j], cloc + bv[i][j-1]);
        }

    if (bv[N-1][N-1] + K >= 2 * N - 1)
    {
        for (int i = 0; i < 2 * N - 1; i++)
            cout << 'a';
        cout << "\n";
        return 0;
    }

    int rc = -1;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (bv[i][j] + K > i + j)
                rc = max (rc, i + j);

    if (rc == -1)
    {
        work[0] = true;
        rc = 0;
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            int j = rc - i;
            if (j < 0 || j >= N) continue;
            if (bv[i][j] + K > i + j)
            {
                if (i < N - 1) work[i+1] = true;
                if (j < N - 1) work[i] = true;
            }
        }

        for (int i = 0; i <= rc; i++)
            cout << 'a';
        rc++;
    }

    while (rc <= 2 * N - 2)
    {
        char bc = 'z';
        for (int i = 0; i < N; i++)
            if (work[i])
                bc = min (bc, s[i][rc-i]);
        cout << bc;
        for (int i = 0; i < N; i++)
            nwork[i] = false;

        for (int i = 0; i < N; i++)
            if (work[i] && s[i][rc-i] == bc)
            {
                if (i < N - 1)
                    nwork[i+1] = true;
                if (rc - i < N - 1)
                    nwork[i] = true;
            }
        rc++;
        for (int i = 0; i < N; i++)
        {
            work[i] = nwork[i];
            nwork[i] = false;
        }
    }
    cout << "\n";
}