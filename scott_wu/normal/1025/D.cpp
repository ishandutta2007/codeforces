#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
typedef long long ll;
const int MAXN = 800;

ll gcf (ll a, ll b)
{
    if (b == 0) return a;
    return gcf (b, a % b);
}

int N;
int arr[MAXN];
bool good[MAXN][MAXN];
bool lgood[MAXN][MAXN];
bool rgood[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            if (gcf (arr[i], arr[j]) > 1)
                good[i][j] = true;
            else
                good[i][j] = false;
        }

    for (int i = 0; i < N; i++)
    {
        if (i > 0)
            rgood[i][i] = good[i-1][i];
        if (i < N - 1)
            lgood[i][i] = good[i+1][i];
    }
    for (int i = 1; i <= N + 1; i++)
        lgood[i][i-1] = rgood[i][i-1] = true;

    for (int m = 1; m < N; m++)
    {
        for (int i = 1; i + m <= N; i++)
        {
            int j = i + m;
            lgood[i][j] = rgood[i][j] = false;
            for (int k = i; k <= j; k++)
            {
                if (!lgood[i][k-1])
                    continue;
                if (!rgood[k+1][j])
                    continue;

                rgood[i][j] |= good[i-1][k];
                lgood[i][j] |= good[j+1][k];
            }
        }
    }

    bool works = false;
    for (int i = 0; i < N; i++)
    {
        if (i > 0 && !lgood[0][i-1])
            continue;
        if (i < N - 1 && !rgood[i+1][N-1])
            continue;
        works = true;
    }
    if (works) cout << "Yes\n";
    else cout << "No\n";
}