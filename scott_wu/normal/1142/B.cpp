#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N, M, Q;
int perm[MAXN];
int nperm[MAXN];

int arr[MAXN];
int lval[MAXN];
int nnext[MAXN];

int anc[MAXN][20];
int nanc[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N >> M >> Q;
    for (int i = 0; i < N; i++)
        cin >> perm[i];
    for (int i = 0; i < N; i++)
        nperm[perm[i]] = perm[(i+1)%N];

    for (int i = 0; i < M; i++)
        cin >> arr[i];
    for (int i = 0; i < MAXN; i++)
        lval[i] = M;

    nnext[M] = M;
    for (int i = M - 1; i >= 0; i--)
    {
        nnext[i] = lval[nperm[arr[i]]];
        lval[arr[i]] = i;
    }

    for (int i = 0; i <= M; i++)
        anc[i][0] = nnext[i];
    for (int i = 1; i < 20; i++)
    {
        for (int j = 0; j <= M; j++)
            anc[j][i] = anc[anc[j][i-1]][i-1];
    }

    for (int i = 0; i < M; i++)
    {
        nanc[i] = i;
        int cval = N - 1;
        for (int j = 0; j < 20; j++)
        {
            if (cval & (1 << j))
                nanc[i] = anc[nanc[i]][j];
        }
    }
    for (int i = M - 2; i >= 0; i--)
    {
        nanc[i] = min (nanc[i], nanc[i+1]);
    }

    for (int i = 0; i < Q; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        if (nanc[x] <= y)
        {
            cout << 1;
        }
        else
            cout << 0;
    }
    cout << "\n";
}