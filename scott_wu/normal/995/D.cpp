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
const int MAXN = (1 << 20) + 100;

int N, R;
int arr[MAXN];
ll tot;

int main()
{
    ios_base::sync_with_stdio(0);

    tot = 0;
    cin >> N >> R;
    for (int i = 0; i < (1 << N); i++)
    {
        cin >> arr[i];
        tot += arr[i];
    }

    cout << fixed << setprecision(8);
    for (int i = 0; i <= R; i++)
    {
        cout << ((double) tot) / (1 << N) << "\n";
        if (i == R)
            break;
        int x, y;
        cin >> x >> y;
        tot -= arr[x];
        arr[x] = y;
        tot += y;
    }
}