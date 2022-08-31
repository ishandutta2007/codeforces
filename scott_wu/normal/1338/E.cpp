#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 8100;

int N;
int deg[MAXN];
bool edge[MAXN][MAXN];
int ord[MAXN];
int pivot;

bool cmp (int x, int y)
{
    return edge[x][pivot] != edge[y][pivot] ? edge[x][pivot] : edge[x][y];
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string s; cin >> s;
        for (int j = 0; j < N / 4; j++)
        {
            int c = (s[j] <= '9' ? s[j] - '0' : 10 + s[j] - 'A');

            for (int k = 0; k < 4; k++)
                if (c & (1 << (3 - k)))
                    edge[i][4*j+k] = true, deg[i]++;
        }
    }

    pivot = 0;
    for (int i = 1; i < N; i++)
        if (deg[i] < deg[pivot])
            pivot = i;

    for (int i = 0; i < N; i++)
        ord[i] = i;
    sort (ord, ord + N, cmp);

    int cloc = 0;
    ll ans = 0;
    while (cloc < N && deg[ord[cloc]] == N - 1 - cloc)
    {
        ans += (1 + 614LL * N) * (N - 1 - cloc);
        cloc++;
    }
    vector <int> v;
    for (int i = cloc; i < N; i++)
        v.push_back(deg[ord[i]]);
    for (int i = 0; i < v.size(); i++)
    {
        int nn = (i + v[i]) % v.size();
        ans += v[i] * 1 + v[nn] * 2 + (v.size() - 1 - v[i] - v[nn]) * 3;
    }
    cout << ans << "\n";
}