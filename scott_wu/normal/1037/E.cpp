#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N, M, K;
pair <int, int> vv[MAXN];
vector <pair <int, int> > edge[MAXN];
bool good[MAXN];
int ndeg[MAXN], res[MAXN];
int cturn;

void dec (int cloc)
{
    if (!good[cloc]) return;
    if (ndeg[cloc] < K)
    {
        good[cloc] = false;
        res[cloc] = cturn;
        //cout << "pop " << cloc << " " << cturn << "\n";
        for (int i = 0; i < edge[cloc].size(); i++)
        {
            if (edge[cloc][i].second < cturn)
            {
                int neigh = edge[cloc][i].first;
                ndeg[neigh]--;
                dec (neigh);
            }
        }
    }
}

void run()
{
    for (int i = 0; i < N; i++)
    {
        good[i] = true;
        ndeg[i] = edge[i].size();
        res[i] = M;
    }

    cturn = M;
    for (int i = 0; i < N; i++)
        if (ndeg[i] < K) dec (i);

    for (int i = M - 1; i >= 0; i--)
    {
        cturn = i;
        int x = vv[i].first, y = vv[i].second;
        if (good[x] && good[y])
        {
            ndeg[x]--;
            ndeg[y]--;
            dec (x);
            dec (y);
        }
    }
}

bool cmp (pair <int, int> left, pair <int, int> right)
{
    return left.second < right.second;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        vv[i] = make_pair (x, y);
        edge[x].push_back(make_pair (y, i));
        edge[y].push_back(make_pair (x, i));
    }

    run();
    sort (res, res + N);

    int cloc = 0;
    for (int i = 0; i < M; i++)
    {
        while (cloc < N && res[cloc] == i)
            cloc++;
        cout << cloc << "\n";
    }
}