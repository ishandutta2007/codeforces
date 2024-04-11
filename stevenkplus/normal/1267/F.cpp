#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 500100;

int N, M;
int K[2];
int l[2];
vector <int> v[2];

vector <pair <int, int> > res;

int deg[MAXN];

void gogo()
{
    for (int i = 0; i < N; i++)
        deg[i] = 1;
    for (int x : v[0])
        deg[x]++;
    for (int x : v[1])
        deg[x]++;

    set <int> s;
    for (int i = 0; i < N; i++)
        if (deg[i] == 1)
            s.insert(i);

    l[0] = l[1] = 0;
    for (int r = 0; r < N - 2; r++)
    {
        int nv = *s.begin();

        int neigh;
        if (nv < K[0])
        {
            neigh = v[1][l[1]];
            l[1]++;
        }
        else
        {
            neigh = v[0][l[0]];
            l[0]++;
        }
        res.push_back (make_pair (nv, neigh));
        deg[nv]--;
        deg[neigh]--;
        if (deg[neigh] == 1)
            s.insert(neigh);
        s.erase(nv);
    }

    int x = *s.begin();
    s.erase(x);
    int y = *s.begin();
    res.push_back(make_pair (x, y));
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N >> M;
    cin >> l[0] >> l[1];
    for (int k = 0; k < 2; k++)
    {
        for (int i = 0; i < l[k]; i++)
        {
            int x; cin >> x;
            v[k].push_back(x - 1);
        }
    }

    if (l[0] > M - 1 || l[1] > N - 1)
    {
        cout << "No\n";
        return 0;
    }

    while (v[0].size() < M - 1)
    {
        v[0].push_back(0);
    }
    while (v[1].size() < N - 1)
    {
        v[1].push_back(N);
    }

    K[0] = N;
    K[1] = M;
    N += M;
    gogo();

    cout << "Yes\n";
    for (auto x : res)
    {
        cout << x.first + 1 << " " << x.second + 1 << "\n";
    }
}