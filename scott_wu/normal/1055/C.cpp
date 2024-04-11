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

int l[2], r[2], t[2];
int len[2];

int gcd (int a, int b)
{
    if (b == 0)
        return a;
    return gcd (b, a % b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    for (int i = 0; i < 2; i++)
        cin >> l[i] >> r[i] >> t[i];
    int g = gcd (t[0], t[1]);

    len[0] = r[0] - l[0] + 1;
    len[1] = r[1] - l[1] + 1;
    for (int i = 0; i < 2; i++)
    {
        l[i] %= g;
    }

    int ans = 0;
    int nn = min (l[0] + len[0], l[1] + len[1]) - max (l[0], l[1]);
    ans = max (ans, nn);
    if (l[0] < l[1])
        l[0] += g;
    else
        l[1] += g;
    nn = min (l[0] + len[0], l[1] + len[1]) - max (l[0], l[1]);
    ans = max (ans, nn);
    
    cout << ans << "\n";
}