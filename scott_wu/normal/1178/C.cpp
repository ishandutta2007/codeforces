#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
 
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

int main()
{
    ios_base::sync_with_stdio(0);
    int W, H;
    cin >> W >> H;
    ll ans = 1;
    for (int i = 0; i < (W + H); i++)
        ans = (2 * ans) % MOD;
    cout << ans << "\n";
}