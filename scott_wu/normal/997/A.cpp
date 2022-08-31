#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 400100;

int N;
ll X, Y;
int arr[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N >> X >> Y;
    for (int i = 0; i < N; i++)
    {
        char c;
        cin >> c;
        arr[i] = c - '0';
    }

    int ncount = 0;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] == 0)
        {
            if (i == 0 || arr[i-1] == 1)
            {
                ncount++;
            }
        }
    }

    ll ans = 0;
    if (ncount == 0)
    {
        cout << ans << "\n";
        return 0;
    }
    ans = Y + min (X, Y) * (ncount - 1);
    cout << ans << "\n";
}