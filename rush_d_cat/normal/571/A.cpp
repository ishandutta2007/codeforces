#include <iostream>
using namespace std;
typedef long long LL;
LL a, b, c, n;
int main()
{
    cin >> a >> b >> c >> n;
    LL ans = (n+3)*(n+2)*(n+1)/6, d;
    for(int i=0;i<=n;i++)
    {
        d = min(n-i, a+i-b-c);
        if(d >= 0) ans -= (d+2)*(d+1)/2;
        d = min(n-i, b+i-a-c);
        if(d >= 0) ans -= (d+2)*(d+1)/2;
        d = min(n-i, c+i-a-b);
        if(d >= 0) ans -= (d+2)*(d+1)/2;
    }
    cout << ans << endl;
}