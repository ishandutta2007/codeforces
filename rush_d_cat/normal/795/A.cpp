#include <iostream>
using namespace std;
typedef long long LL;
LL n, c1, c2, a;
char c;
int main()
{
    cin >> n >> c1 >> c2;
    for(int i=1;i<=n;i++)
    {
        cin >> c;if(c == '1') a++;
    }
    LL ans = 1e18;
    for(LL i=a;i>=1;i--)
    {
        ans = min(ans, (n%i)*(c1+(n/i)*(n/i)*c2) + (i-n%i)*(c1+(n/i-1)*(n/i-1)*c2));
    }
    cout << ans << endl;
}