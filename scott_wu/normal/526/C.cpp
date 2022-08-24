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

ll C, H1, H2, W1, W2;

int main()
{
    ios_base::sync_with_stdio(0);
    
    cin >> C >> H1 >> H2 >> W1 >> W2;
    ll ans = 0;
    
    if (C > 4 * W1 * W2)
    {
        ll f = C / (W1 * W2) - 4;
        ans += f * max (W1 * H2, W2 * H1);
        C -= f * W1 * W2;
    }
    
    if (W1 > W2)
    {
        swap (W1, W2);
        swap (H1, H2);
    }
    
    ll res = 0;
    for (int i = 0; i * W2 <= C; i++)
    {
        res = max (res, ans + i * H2 + ((C - i * W2) / W1) * H1);
    }
    cout << res << "\n";
    return 0;
}