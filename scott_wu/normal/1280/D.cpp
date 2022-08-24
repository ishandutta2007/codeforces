#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 3100;

int N, M;
ll ndiff[MAXN];
int nhi[MAXN][MAXN];
ll nscore[MAXN][MAXN];

int new_hi[MAXN];
ll new_score[MAXN];

vector <int> edge[MAXN];
int ssize[MAXN];

void flood (int cloc, int last)
{
    ssize[cloc] = 0;
    nhi[cloc][0] = 0;
    nscore[cloc][0] = ndiff[cloc];

    for (int neigh : edge[cloc])
    {
        if (neigh == last) continue;
        flood (neigh, cloc);

        for (int i = 0; i <= ssize[cloc] + ssize[neigh]; i++)
        {
            new_hi[i] = 0;
            new_score[i] = -1e15;
        }
        for (int i = 0; i <= ssize[neigh]; i++)
            for (int j = 0; j <= ssize[cloc]; j++)
            {
                int nb = nhi[neigh][i] + nhi[cloc][j];
                if (nb > new_hi[i+j])
                {
                    new_hi[i+j] = nb;
                    new_score[i+j] = -1e15;
                }
                if (nb == new_hi[i+j])
                    new_score[i+j] = max (new_score[i+j], nscore[neigh][i] + nscore[cloc][j]);
            }
        for (int i = 0; i <= ssize[cloc] + ssize[neigh]; i++)
        {
            nhi[cloc][i] = new_hi[i];
            nscore[cloc][i] = new_score[i];
        }

        ssize[cloc] += ssize[neigh];
    }

    nhi[cloc][ssize[cloc]+1] = 0;
    nscore[cloc][ssize[cloc]+1] = -1e15;
    if (cloc == 0)
    {
        nhi[cloc][M] = -1;
    }
    for (int i = ssize[cloc]; i >= 0; i--)
    {
        int ntot = nhi[cloc][i];
        if (nscore[cloc][i] > 0) ntot++;
        if (ntot > nhi[cloc][i+1])
        {
            nhi[cloc][i+1] = ntot;
            nscore[cloc][i+1] = -1e15;
        }
        if (ntot == nhi[cloc][i+1])
            nscore[cloc][i+1] = max (nscore[cloc][i+1], 0LL);
    }
    ssize[cloc]++;
}

void gogo()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        ndiff[i] = 0;
        edge[i].clear();
    }
    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= N; j++)
        {
            nhi[i][j] = 0;
            nscore[i][j] = -1e15;
        }

    for (int i = 0; i < N; i++)
    {
        int b; cin >> b;
        ndiff[i] -= b;
    }
    for (int i = 0; i < N; i++)
    {
        int w; cin >> w;
        ndiff[i] += w;
    }

    for (int i = 0; i < N - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }

    flood (0, 0);

    for (int i = 0; i < N; i++)
    {
        ssize[i] = 0;
        edge[i].clear();
    }

    cout << nhi[0][M] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 0; t < T; t++)
        gogo();
}