#include <iostream>
#include <iomanip>
#include <map>
#include <queue>
#include <algorithm>
#include <string>
#include <set>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    int N; cin >> N;

    int ans = 1e6;
    for (int i = 2; i <= 10000; i++)
    {
        int l = i / 2, r = (i + 1) / 2;
        if (l * r >= N)
            ans = min (ans, 2 * (l + r));
    }
    cout << ans << "\n";
}