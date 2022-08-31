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

    ll N, M;
    cin >> N >> M;
    ll lo = max (0LL, N - 2 * M);
    ll ctot = 0;
    while (ctot * (ctot - 1) / 2 < M)
        ctot++;
    cout << lo << " " << N - ctot << "\n";
}