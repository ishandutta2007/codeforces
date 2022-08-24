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
    int x = 25;
    for (int i = 0; i < N; i++)
    {
        int k; cin >> k;
        x = max (x, k);
    }

    cout << x - 25 << "\n";
}