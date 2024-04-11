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

int N;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N;
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        ans = max (ans, x + y);
    }
    cout << ans << "\n";
}