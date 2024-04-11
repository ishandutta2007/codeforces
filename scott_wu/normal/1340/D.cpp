#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

int N, K;
vector <int> edge[MAXN];
int ans;

vector <pair <int, int> > vres;

void gogo (int cloc, int cpar, int cv)
{
    //cout << cloc << " " << cpar << " " << cv << endl;
    int cret = cv;
    vres.push_back (make_pair (cloc, cv));

    int deg = edge[cloc].size();
    for (int neigh : edge[cloc])
    {
        if (neigh == cpar) continue;
        if (cloc > 0 && cv == ans)
        {
            cv = ans - deg;
            vres.push_back (make_pair (cloc, cv));
        }

        cv++;
        gogo (neigh, cloc, cv);
        vres.push_back (make_pair (cloc, cv));
    }
    if (cloc > 0 && cv >= cret)
    {
        cv = cret - 1;
        vres.push_back (make_pair (cloc, cv));
    }
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N;
    //N=1
    for (int i = 0; i < N - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        edge[x].push_back (y);
        edge[y].push_back (x);
    }

    ans = 0;
    for (int i = 0; i < N; i++)
        ans = max (ans, (int) edge[i].size());

    gogo (0, -1, 0);

    cout << vres.size() << "\n";
    for (auto x : vres)
    {
        cout << x.first + 1 << " " << x.second << "\n";
    }
}