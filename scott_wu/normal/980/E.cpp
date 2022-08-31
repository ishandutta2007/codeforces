#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
const int MAXN = 1000100;

int N, K;
vector <int> edge[MAXN];
int anc[MAXN][23];
bool has[MAXN];

int get_anc (int cloc, int nanc)
{
    for (int i = 0; i <= 20; i++)
        if (nanc & (1 << i))
            cloc = anc[cloc][i];
    return cloc;
}

void flood (int cloc, int last)
{
    anc[cloc][0] = last;
    for (int i = 0; i <= 20; i++)
    {
        anc[cloc][i+1] = anc[anc[cloc][i]][i];
    }
    for (int i = 0; i < edge[cloc].size(); i++)
    {
        int neigh = edge[cloc][i];
        if (neigh == last) continue;
        flood (neigh, cloc);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N >> K;
    K = N - K;
    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a = N - a;
        b = N - b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    for (int i = 0; i < N; i++)
        has[i] = false;
    has[0] = true;

    flood (0, 0);

    K--;
    for (int i = 1; i < N; i++)
    {
        if (!has[i])
        {
            int nh = get_anc(i, K);
            if (!has[nh])
                continue;
            int cloc = i;
            while (true)
            {
                if (has[cloc])
                    break;
                has[cloc] = true;
                K--;
                cloc = anc[cloc][0];
            }
        }
    }

    vector <int> v;
    for (int i = 0; i < N; i++)
        if (!has[i])
            v.push_back(N-i);
    sort (v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        if (i) cout << " ";
        cout << v[i];
    }
    cout << "\n";
}