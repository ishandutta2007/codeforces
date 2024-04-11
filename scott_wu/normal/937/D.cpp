#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N, M, S;
vector <int> edge[MAXN];
vector <int> redge[MAXN];
bool seen[MAXN][2];
int lval[MAXN][2];
vector <int> v;
bool bad[MAXN];

void run_solve(int cloc, int cv)
{
    if (seen[cloc][cv])
        return;
    seen[cloc][cv] = true;
    for (int i = 0; i < edge[cloc].size(); i++)
    {
        int neigh = edge[cloc][i];
        if (!seen[neigh][1-cv])
        {
            lval[neigh][1-cv] = cloc;
            run_solve(neigh, 1 - cv);
        }
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int t; cin >> t;
        for (int j = 0; j < t; j++)
        {
            int k; cin >> k;
            k--;
            edge[i].push_back(k);
            redge[k].push_back(i);
        }
    }

    for (int i = 0; i < MAXN; i++)
        seen[i][0] = seen[i][1] = false;
    cin >> S;
    S--;
    run_solve(S, 0);

    int win = -1;
    for (int i = 0; i < N; i++)
        if (seen[i][1])
            if (edge[i].size() == 0)
                win = i;

    if (win != -1)
    {
        int cloc = win;
        v.push_back(cloc);
        int cv = 1;
        while (cloc != S || cv != 0)
        {
            cloc = lval[cloc][cv];
            cv = 1 - cv;
            v.push_back(cloc);
        }
        cout << "Win\n";
        for (int i = 0; i < v.size(); i++)
        {
            if (i)
                cout << " ";
            cout << v[v.size()-1-i] + 1;
        }
        cout << "\n";
        return 0;
    }
    bool draw = false;

    for (int i = 0; i < N; i++)
    {
        bad[i] = false;
    }
    v.clear();
    for (int i = 0; i < N; i++)
    {
        lval[i][0] = edge[i].size();
        if (lval[i][0] == 0)
        {
            bad[i] = true;
            v.push_back(i);
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < redge[v[i]].size(); j++)
        {
            int neigh = redge[v[i]][j];
            lval[neigh][0]--;
            if (lval[neigh][0] == 0)
            {
                bad[neigh] = true;
                v.push_back(neigh);
            }
        }
    }

    if (!bad[S])
        cout << "Draw\n";
    else
        cout << "Lose\n";
}