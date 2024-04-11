#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

int N;
pair <int, int> num[MAXN];
int numlist[2*MAXN];

bool check (int x)
{
    int res = 0;
    for (int i = 0; i < N; i++)
        if (num[i].first == x || num[i].second == x)
            res++;
    return ((2 * res) >= N);
}

int solve (int x)
{
    int d = 0;
    for (int i = 0; i < N; i++)
        if (num[i].first == x)
            d++;
    return max (0, (N + 1) / 2 - d);
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> num[i].first >> num[i].second;
        numlist[2*i] = num[i].first;
        numlist[2*i+1] = num[i].second;
    }
    sort (numlist, numlist + 2 * N);
    int cur = 0;
    int ans = N + 1;
    while (cur < 2 * N)
    {
        int next = cur;
        while (next < 2 * N && numlist[cur] == numlist[next])
            next++;
        int sz = next - cur;
        if (sz * 2 >= N)
            if (check (numlist[cur]))
                ans = min (ans, solve (numlist[cur]));
        cur = next;
    }
    if (ans == N + 1)
    {
        cout << "-1\n";
    }
    else
    {
        cout << ans << "\n";
    }
    //system ("Pause");
    return 0;
}