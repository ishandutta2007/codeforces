#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N, M, K, Q;
pair <int, int> treasure[MAXN];
int ndist;
ll dist[MAXN][2];
ll lloc[MAXN][2];
int nleft[MAXN], nright[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);

    for (int i = 0; i < MAXN; i++)
    {
        nleft[i] = -1e9;
        nright[i] = 1e9;
    }

    cin >> N >> M >> K >> Q;
    swap (N, K);
    for (int i = 0; i < N; i++)
        cin >> treasure[i].first >> treasure[i].second;
    for (int i = 0; i < Q; i++)
    {
        int t; cin >> t;
        nleft[t] = nright[t] = t;
    }
    for (int i = 1; i < MAXN; i++)
        nleft[i] = max (nleft[i], nleft[i-1]);
    for (int i = MAXN - 2; i >= 0; i--)
        nright[i] = min (nright[i], nright[i+1]);

    treasure[N] = make_pair (1, 1);
    N++;
    sort (treasure, treasure + N);

    ndist = 0;
    int cloc = 0;
    while (cloc < N)
    {
        int cy = treasure[cloc].first;
        lloc[ndist][0] = treasure[cloc].second;

        while (cloc < N - 1 && treasure[cloc+1].first == cy)
            cloc++;
        lloc[ndist][1] = treasure[cloc].second;
        cloc++;

        ndist++;
    }

    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < 2; j++)
            dist[i][j] = 1e15;
    dist[0][1] = lloc[0][1] - lloc[0][0];

    for (int i = 0; i < ndist - 1; i++)
    {
        for (int j = 0; j < 2; j++)
            dist[i][j] = min (dist[i][j], dist[i][1-j] + abs (lloc[i][0] - lloc[i][1]));

        //cout << dist[i][0] << " " << dist[i][1] << " " << lloc[i][0] << " " << lloc[i][1] << "\n";

        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                cloc = lloc[i][j];
                int nloc = lloc[i+1][1-k];
                ll cv = min (abs (cloc - nleft[cloc]) + abs (nloc - nleft[cloc]),
                             abs (cloc - nright[cloc]) + abs (nloc - nright[cloc]));
                dist[i+1][k] = min (dist[i+1][k], dist[i][j] + cv + abs (lloc[i+1][1] - lloc[i+1][0]));
            }
        }
    }
    ll ans = min (dist[ndist-1][0], dist[ndist-1][1]);
    ans += treasure[N-1].first - 1;
    cout << ans << "\n";
}