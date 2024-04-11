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
    int N, K; cin >> N >> K;

    cout << ((K > 0 && K < N) ? 1 : 0) << " " << min (2 * K, N - K) << "\n";
}