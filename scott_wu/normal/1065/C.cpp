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
const int MAXN = 200100;

int N, K;
int nh[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        int x; cin >> x;
        nh[x]++;
    }

    int ans = 0, cc = K;
    for (int i = MAXN - 2; i >= 1; i--)
    {
        nh[i] += nh[i+1];
        if (nh[i] == N) break;
        if (cc >= nh[i])
        {
            cc -= nh[i];
        }
        else
        {
            cc = K - nh[i];
            ans++;
        }
    }
    if (cc < K) ans++;
    cout << ans << "\n";
}