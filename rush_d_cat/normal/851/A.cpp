#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
int n, k, t;
int main()
{
    cin >> n >> k >> t;
    int x = min(t, n + k - t);
    int ans = min(x, k);
    cout << ans << endl;
}