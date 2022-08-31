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
const int MAXN = 100100;
const int MAXM = 12;

int N, M;
int arr[MAXM][MAXN];
int aloc[MAXM][MAXN]; // loc of # i
int ans[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
            arr[i][j]--;
            aloc[i][arr[i][j]] = j;
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (i == 0) ans[i] = 1;
        else ans[i] = max (1, ans[i-1] - 1);
        while (true)
        {
            if (i + ans[i] >= N) break;
            int cval = arr[0][i+ans[i]];
            int oval = arr[0][i];
            bool bad = false;
            for (int j = 0; j < M; j++)
                if (aloc[j][cval] != ans[i] + aloc[j][oval])
                {
                    bad = true;
                }
            if (bad) break;
            ans[i]++;
        }
    }

    ll res = 0;
    for (int i = 0; i < N; i++)
        res += ans[i];
    cout << res << "\n";
}