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
    int T; cin >> T;
    for (int test = 0; test < T; test++)
    {
        ll a, b, k;
        cin >> a >> b >> k;
        cout << (a - b) * (k / 2) + a * (k % 2) << "\n";
    }
}