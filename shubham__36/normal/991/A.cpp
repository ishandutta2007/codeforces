#include <iostream>

using namespace std;

int main()
{
    int a, b , c ,d,ans=0;
    cin >> a >> b >> c >> d;
    if (a>=c && b >= c) ans = d-(a + b -c);
    if(ans >= 1) cout << ans << endl ;
    else cout << -1 << endl ;
    return 0;
}