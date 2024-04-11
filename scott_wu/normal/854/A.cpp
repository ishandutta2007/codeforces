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

int gcf (int a, int b)
{
    return ((b == 0) ? a : gcf (b, a % b));
}

int main()
{
    ios_base::sync_with_stdio(0);

    int N; cin >> N;

    int ans = 1;
    for (int i = 2; i * 2 < N; i++)
        if (gcf (i, N) == 1)
            ans = i;
    cout << ans << " " << N - ans << "\n";
}