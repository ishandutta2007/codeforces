#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 1000100;

int N, M;
vector<int> oedge[MAXN], iedge[MAXN];
int spec[MAXN], take[MAXN];

int main()
{
    scanf ("%d %d", &N, &M);
    for (int i = 0; i < M; i++)
    {
        int x, y;
        scanf ("%d %d", &x, &y);
        oedge[x].push_back(y);
        iedge[y].push_back(x);
    }

    for (int i = 1; i <= N; i++)
    {
        if (spec[i]) continue;
        spec[i] = 1;
        for (int j = 0; j < oedge[i].size(); j++)
            if (!spec[oedge[i][j]]) spec[oedge[i][j]] = 2;
    }

    int np = 0;
    for (int i = N; i >= 1; i--)
    {
        if (spec[i] != 1) continue;
        take[i] = true;
        for (int j = 0; j < iedge[i].size(); j++)
            if (take[iedge[i][j]]) take[i] = false;
        if (take[i]) np++;
    }

    printf("%d\n", np);
    for (int i = 1; i <= N; i++)
        if (take[i]) printf("%d ", i);
}