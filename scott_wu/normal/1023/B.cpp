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

ll N, K;

ll ret()
{
    if (K >= 2 * N || K <= 2) return 0;
    if (N == 1) return 0;
    if (K > N + 1)
        K = (2 * N + 2) - K;
    // 3..N+1
    return (K - 1) / 2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> N >> K;
    cout << ret() << "\n";
}