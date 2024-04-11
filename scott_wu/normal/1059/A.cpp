#include <iostream>
#include <iomanip>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <ctime>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    int N, L, A;
    cin >> N >> L >> A;

    int clast = 0, ans = 0;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        ans += (x - clast) / A;
        clast = x + y;
    }
    ans += (L - clast) / A;
    cout << ans << "\n";
}