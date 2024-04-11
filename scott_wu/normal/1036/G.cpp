#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;
typedef long long ll;
const int MAXN = 1000100;

int N, M;
vector <int> edge[MAXN];
int ideg[MAXN];
vector <int> source, sink;
vector <int> see;
bool seen[MAXN];

void flood (int cloc)
{
    if (seen[cloc]) return;
    seen[cloc] = true;
    for (int i : edge[cloc])
        flood (i);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int x, y; cin >> x >> y;
        x--, y--;
        edge[x].push_back(y);
        ideg[y] = 1;
    }

    for (int i = 0; i < N; i++)
    {
        if (!ideg[i])
            source.push_back(i);
        if (!edge[i].size())
            sink.push_back(i);
    }

    int D = source.size();
    for (int i = 0; i < D; i++)
    {
        for (int j = 0; j < N; j++)
            seen[j] = 0;

        flood (source[i]);
        see.push_back(0);
        for (int j = 0; j < D; j++)
            if (seen[sink[j]])
                see[i] |= (1 << j);
    }

    bool bad = false;
    for (int i = 1; i < (1 << D) - 1; i++)
    {
        int r = 0;
        for (int j = 0; j < D; j++)
            if (i & (1 << j))
                r |= see[j];
        if (__builtin_popcount(r) <= __builtin_popcount(i))
            bad = true;
    }
    if (bad) cout << "NO\n";
    else cout << "YES\n";
}