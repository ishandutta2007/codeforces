#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 2100;

int N, root;
int cv[MAXN];
vector <int> child[MAXN];
vector <int> tree[MAXN]; // grandchildren etc
int loc[MAXN];
int oloc[MAXN];

void gswap (int x, int y)
{
    swap (loc[x], loc[y]);
    swap (oloc[loc[x]], oloc[loc[y]]);
}

bool cmp (int x, int y)
{
    return loc[x] < loc[y];
}

bool bad;

void gogo (int cloc)
{
    for (int neigh : child[cloc])
    {
        gogo (neigh);
        for (int guy : tree[neigh])
            tree[cloc].push_back(guy);
    }
    tree[cloc].push_back(cloc);
    sort (tree[cloc].begin(), tree[cloc].end(), cmp);
    int ncur = 0;
    //cout << cloc << " " << tree[cloc].size() << " " << ncur << "\n";
    while (tree[cloc][ncur] != cloc) ncur++;
    if (cv[cloc] > tree[cloc].size() - 1)
    {
        bad = true;
        return;
    }

    while (ncur > cv[cloc])
    {
        gswap (cloc, tree[cloc][ncur-1]);
        ncur--;
    }
    while (ncur < cv[cloc])
    {
        //cout << ncur << "\n";
        gswap (cloc, tree[cloc][ncur+1]);
        ncur++;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);

    bad = false;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int par, c;
        cin >> par >> c;
        par--;
        if (par == -1)
            root = i;
        else
            child[par].push_back(i);

        cv[i] = c;
    }

    for (int i = 0; i < N; i++)
        oloc[i] = loc[i] = i;

    gogo (root);
    if (bad)
    {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for (int i = 0; i < N; i++)
    {
        if (i) cout << " ";
        cout << loc[i] + 1;
    }
    cout << "\n";
}