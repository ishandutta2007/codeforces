#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 310;

int N, M;
int nv[MAXN][MAXN];

void gogo()
{
    cin >> N >> M;
    bool bad = false;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> nv[i][j];

            int nneigh = 0;
            if (i) nneigh++;
            if (i < N - 1) nneigh++;
            if (j) nneigh++;
            if (j < M - 1) nneigh++;

            if (nneigh < nv[i][j])
                bad = true;
            nv[i][j] = nneigh;
        }
    if (bad) cout << "NO\n";
    else
    {
        cout << "YES\n";
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (j) cout << " ";
                cout << nv[i][j];
            }
            cout << "\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 0; t < T; t++)
        gogo();
}