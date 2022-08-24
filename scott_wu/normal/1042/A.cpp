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
    int N, M;
    cin >> N >> M;
    int hi = 0, tot = 0;
    for (int i = 0; i < N; i++)
    {
        int x; cin >> x;
        tot += x;
        hi = max (hi, x);
    }

    cout << max (hi, (tot + M + N - 1) / N) << " " << hi + M << "\n";
}