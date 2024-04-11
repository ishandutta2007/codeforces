#include <iostream>
#include <fstream>
using namespace std;
typedef long long ll;
ll A, B, x, y, z;
int main()
{
    cin>>A>>B;
    cin>>x>>y>>z;
    ll s = 2*x+y;
    ll t = 3*z+y;
    ll ans = 0;
    if(s>=A)
    {
        ans += (s-A);
    }
    if(t >= B)
    {
        ans += (t-B);
    }
    cout<<ans<<endl;
}