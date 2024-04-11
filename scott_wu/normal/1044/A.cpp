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
const int MAXN = 300100;

int N, M;
int X[MAXN];
int Y[MAXN];
map <int, int> mm;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N >> M;
    mm[1.1e9];
    for (int i = 0; i < N; i++)
    {
        cin >> X[i];
        mm[X[i]];
    }

    int nmap = 0;
    for (auto it = mm.begin(); it != mm.end(); it++)
        it->second = nmap++;

    int ny = 0, nadd = 0;
    for (int i = 0; i < M; i++)
    {
        int x1, x2, y;
        cin >> x1 >> x2 >> y;
        if (x1 != 1) continue;
        if (x2 == 1000000000)
        {
            nadd++;
            continue;
        }

        int nhi = mm.upper_bound(x2)->second;
        Y[ny++] = nhi;
    }

    M = ny;
    sort (Y, Y + M);

    int ans = 1e9;
    for (int i = 0; i <= M; i++)
    {
        int best = (M - i);
        if (i)
            best += Y[i-1];
        ans = min (ans, best);
    }
    cout << ans + nadd << "\n";
}