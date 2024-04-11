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

    int N; cin >> N;
    int lo = 1e9, hi = 0;
    for (int i = 0; i < N; i++)
    {
        int x; cin >> x;
        lo = min (lo, x);
        hi = max (hi, x);
    }
    cout << (hi - lo - N + 1) << "\n";
}