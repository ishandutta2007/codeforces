#include <iostream>
using namespace std;
typedef long long LL;
int n; LL a[102];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    LL ans = 0;
    for (int i = 1; i <= n; i ++) {
        ans += (a[i] - 1) * i;
    }
    ans += n;
    cout << ans << endl;
}