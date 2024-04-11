#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N, M;
vector <int> edge[MAXN];
vector <int> plist[MAXN];
int dist[MAXN];
bool seen[MAXN];

int K;
int stop[MAXN];

void dijk (int cs)
{
    dist[0] = 0;
    priority_queue <pair <int, int> > pq;
    pq.push(make_pair(-dist[cs], cs));

    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        int cloc = cur.second, cdist = -cur.first;
        if (seen[cloc]) continue;

        seen[cloc] = true;
        dist[cloc] = cdist;
        for (int neigh : edge[cloc])
            pq.push(make_pair(-(cdist + 1), neigh));
    }
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;

        edge[y].push_back(x);
        plist[x].push_back(y);
    }

    for (int i = 0; i < N; i++)
    {
        dist[i] = 1e9;
        seen[i] = false;
    }

    cin >> K;
    for (int i = 0; i < K; i++)
    {
        cin >> stop[i];
        stop[i]--;
    }

    dijk (stop[K-1]);

    int lo = 0, hi = 0;
    for (int i = 0; i + 1 < K; i++)
    {
        int x = stop[i], y = stop[i+1];
        if (dist[x] <= dist[y])
        {
            lo++;
            hi++;
        }
        else
        {
            int np = 0;
            for (int g : plist[x])
                if (dist[x] > dist[g])
                    np++;
            if (np >= 2) hi++;
        }
    }

    cout << lo << " " << hi << "\n";
}