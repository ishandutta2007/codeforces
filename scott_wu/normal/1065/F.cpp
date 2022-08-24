#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 1000100;

int N, K;
vector <int> child[MAXN];
int nfree[MAXN], npaid[MAXN], dep[MAXN];

void flood (int cloc)
{
    if (!child[cloc].size())
    {
        dep[cloc] = 0;
        nfree[cloc] = 1;
        npaid[cloc] = 0;
        return;
    }

    int pbest = 0, ftot = 0;
    dep[cloc] = 1e9;
    for (int son : child[cloc])
    {
        flood (son);
        dep[cloc] = min (dep[cloc], dep[son] + 1);
        ftot += nfree[son];
        pbest = max (pbest, npaid[son]);
    }
    npaid[cloc] = pbest;
    if (dep[cloc] < K)
        nfree[cloc] += ftot;
    else
        npaid[cloc] += ftot;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N >> K;
    for (int i = 1; i < N; i++)
    {
        int a; cin >> a;
        a--;
        child[a].push_back(i);
    }

    flood (0);
    cout << nfree[0] + npaid[0] << "\n";
}