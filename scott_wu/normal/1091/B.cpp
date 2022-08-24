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
    ll xtot = 0, ytot = 0;
    for (int i = 0; i < 2 * N; i++)
    {
        int x, y;
        cin >> x >> y;
        xtot += x;
        ytot += y;
    }
    xtot /= N;
    ytot /= N;
    cout << xtot << " " << ytot << "\n";
}