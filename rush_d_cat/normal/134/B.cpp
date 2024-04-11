#include <iostream>
using namespace std;
int k;
int gcd(int x, int y)
{
    if(x%y==0) return y==1?(x-1):10000000;
    return x/y + gcd(y, x%y);
}
int main()
{
    cin >> k;
    int ans = k;
    for(int i=1;i<=k;i++)
    {
        ans = min(ans, gcd(k, i));
    }
    cout << ans << endl;
}