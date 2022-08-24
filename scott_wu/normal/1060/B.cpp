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

    ll N; cin >> N;
    int ans = 0;
    while (N % 10 == 9)
    {
        ans += 9;
        N /= 10;
    }

    if (!N)
    {
        cout << ans << "\n";
        return 0;
    }

    int ndig = 0;
    while (N)
    {
        ans += N % 10;
        ndig++;
        N /= 10;
    }
    cout << ans + (ndig - 1) * 9 << "\n";
}