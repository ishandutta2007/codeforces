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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int W, H, K;
    cin >> W >> H >> K;

    int ans = 0;
    for (int i = 0; i < K; i++)
    {
        ans += 2 * (W + H - 2);
        W -= 4;
        H -= 4;
    }
    cout << ans << "\n";
}