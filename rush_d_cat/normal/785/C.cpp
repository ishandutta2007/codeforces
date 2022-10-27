#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
LL n, m, ans;
int main()
{
    cin >> n >> m;
    if(n == 1)
    {
        ans = 1;
        cout << ans << endl;
        return 0;
    }
    if(m >= n)
    {
        ans = n;
        cout << ans << endl;
        return 0;
    }
    ans = m;
    LL res = n - m;
    LL l = 0, r = 1e9 + 1e9/2;
    while(r-l>1)
    {
        LL x = (l+r)/2;
        if((x*x+x)/2 < res)
        {
            l = x;
        } else {
            r = x;
        }
    }
    ans += (l+1);
    cout << ans << endl;
}