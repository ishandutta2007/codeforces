#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 5100;

int N, M;
vector <int> edge[MAXN];
int cdist[MAXN][MAXN];

int loc[3];
int target[3];
int eloc;

void play (bool finish)
{
    cout << loc[0] + 1 << " " << loc[1] + 1 << " " << loc[2] + 1 << "\n";
    cout << flush;

    if (!finish)
    {
        cin >> eloc;
        eloc--;
    }
}

void bfs (int cloc)
{
    vector <int> q;
    q.push_back(cloc);
    cdist[cloc][cloc] = 0;

    for (int nq = 0; nq < q.size(); nq++)
    {
        int ccur = q[nq];
        for (int neigh : edge[ccur])
        {
            if (cdist[cloc][neigh] > cdist[cloc][ccur] + 1)
            {
                cdist[cloc][neigh] = cdist[cloc][ccur] + 1;
                q.push_back(neigh);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    srand(8409);
    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            cdist[i][j] = MAXN;

    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < edge[i].size(); j++)
            swap (edge[i][j], edge[i][rand() % (j + 1)]);
    }

    for (int i = 0; i < N; i++)
        bfs (i);

    for (int i = 0; i < 3; i++)
    {
        while (true)
        {
            loc[i] = rand() % N;
            bool bad = false;
            for (int j = 0; j < i; j++)
                if (loc[j] == loc[i]) bad = true;
            if (!bad) break;
        }
    }

    play(false);
    for (int run = 0; run < N; run++)
    {
        if (eloc == loc[0] || eloc == loc[1] || eloc == loc[2]) break;
        vector <pair <int, pair <int, int> > > v;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < edge[eloc].size(); j++)
            {
                v.push_back (make_pair (cdist[i][j], make_pair (i, j)));
            }
        sort (v.begin(), v.end());
        for (int i = 0; i < 3; i++)
            target[i] = -1;
        for (auto ppp : v)
        {
            int ci = ppp.second.first, cv = ppp.second.second;
            bool bad = false;
            for (int i = 0; i < 3; i++)
                if (target[i] == cv) bad = true;
            if (target[ci] == -1 && !bad)
                target[ci] = cv;
        }
        for (int i = 0; i < 3; i++)
            if (target[i] == -1) target[i] = 0;

        bool done = false;
        for (int i = 0; i < 3; i++)
        {
            if (cdist[loc[i]][eloc] == 1)
            {
                done = true;
                loc[i] = eloc;
                break;
            }
            else
            {
                vector <int> choice;
                int nneigh = edge[eloc][target[i]];
                for (int neigh : edge[loc[i]])
                    if (cdist[neigh][nneigh] < cdist[loc[i]][nneigh])
                    {
                        choice.push_back(neigh);
                    }
                loc[i] = choice[rand() % choice.size()];
            }
        }

        play(done);
    }
}