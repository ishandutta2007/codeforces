#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 10100;

int N, K;
int color[MAXN];
vector <int> v[MAXN];
bool use[MAXN];

vector <pair <int, pair <int, int> > > res;

void gogo()
{
    cin >> N >> K;
    for (int i = 0; i < N * K; i++)
    {
        cin >> color[i];
        color[i]--;

        v[color[i]].push_back(i);
        use[i] = false;
    }

    for (int i = 0; i < N; i++)
    {
        int t = i % (K - 1) + 1;

        int nloc = -1;
        for (int j = 0; j < N; j++)
        {
            if (use[j]) continue;
            if (nloc == -1 || v[j][t] < v[nloc][t])
                nloc = j;
        }

        use[nloc] = true;
        res.push_back (make_pair (nloc, make_pair (v[nloc][t-1], v[nloc][t])));
    }

    sort(res.begin(), res.end());

    for (int i = 0; i < N; i++)
    {
        cout << res[i].second.first + 1 << " " << res[i].second.second + 1 << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T = 1;
    for (int t = 0; t < T; t++)
        gogo();
}