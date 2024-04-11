#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXN = 1000100;

int N, Q;
ll arr[MAXN];
ll ps[2*MAXN];
int nval[2*MAXN];
ll tot;

int run (int start, int cap)
{
    int cloc = start, tot = 0;
    while (cloc < start + N && tot < cap)
    {
        cloc = nval[cloc];
        tot++;
    }
    return tot;
}

int solve (ll B)
{
    if (B >= tot)
        return 1;
    
    int cloc = 2 * N;
    for (int i = 2 * N - 1; i >= 0; i--)
    {
        while (ps[cloc] - ps[i] > B)
            cloc--;
        nval[i] = cloc;
    }
    
    int cap = run (0, 1e9);
    int bloc = -1, bval = 1e9;
    for (int i = 0; i < N; i++)
        if (nval[i] - i < bval)
        {
            bloc = i;
            bval = nval[i] - i;
        }
    
    for (int i = bloc; i <= bloc + bval; i++)
    {
        cap = min (cap, run (i % N, cap));
    }
    return cap;
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    cin >> N >> Q;
    tot = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        tot += arr[i];
    }
    
    ps[0] = 0;
    for (int i = 0; i < 2 * N; i++)
        ps[i+1] = ps[i] + arr[i % N];
    
    ll B;
    for (int i = 0; i < Q; i++)
    {
        cin >> B;
        cout << solve (B) << "\n";
    }
    return 0;
}