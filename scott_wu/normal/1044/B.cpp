#include <iostream>
#include <iomanip>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <ctime>

using namespace std;
typedef long long ll;
const int MAXN = 1100;

int T;
int N;
vector <int> edge[MAXN];
bool k1[MAXN];
bool k2[MAXN];
bool seen[MAXN];
bool found;
int nbest;

void kflood (int cloc)
{
    if (seen[cloc]) return;
    if (found) return;
    if (k1[cloc])
    {
        found = true;
        nbest = cloc;
        return;
    }
    seen[cloc] = true;

    for (int neigh : edge[cloc])
    {
        kflood (neigh);
    }
}

void respond (int x)
{
    if (x != -1) x++;
    cout << "C " << x << endl;
}

int ask (int x, char c)
{
    cout << c << " " << x + 1 << endl;
    int r; cin >> r;
    r--;
    return r;
}

void figure()
{
    for (int i = 0; i < MAXN; i++)
    {
        edge[i].clear();
        k1[i] = false;
        k2[i] = false;
        seen[i] = false;
    }

    cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        int a, b; cin >> a >> b;
        a--, b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    int n1;
    cin >> n1;
    for (int i = 0; i < n1; i++)
    {
        int x; cin >> x;
        x--;
        k1[x] = true;
    }
    int n2;
    cin >> n2;
    for (int i = 0; i < n2; i++)
    {
        int x; cin >> x;
        x--;
        k2[x] = true;
    }

    for (int i = 0; i < N; i++)
    {
        if (k2[i])
        {
            int cloc = ask (i, 'B');

            if (k1[cloc])
            {
                respond (cloc);
                return;
            }
            found = false;
            nbest = -1;
            kflood (cloc);

            int nloc = ask (nbest, 'A');
            if (k2[nloc])
                respond (nbest);
            else
                respond (-1);
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> T;
    for (int i = 0; i < T; i++)
        figure();
}