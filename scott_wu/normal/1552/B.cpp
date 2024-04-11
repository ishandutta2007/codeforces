#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 50100;

int N;
int sc[MAXN][5];

bool better (int i, int j)
{
    int s = 0;
    for (int x = 0; x < 5; x++)
        if (sc[i][x] < sc[j][x]) s++;
    return s >= 3;
}

void gogo()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 5; j++)
            cin >> sc[i][j];
    }

    int res = 0;
    for (int i = 1; i < N; i++)
    {
        if (better (i, res))
            res = i;
    }

    bool win = true;
    for (int i = 0; i < N; i++)
    {
        if (i == res) continue;
        if (better (i, res)) win = false;
    }

    if (win) cout << res + 1 << "\n";
    else cout << "-1\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 0; t < T; t++)
        gogo();
}