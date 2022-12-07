#include <iostream>
#include <fstream>
using namespace std;
typedef long long ll;
ll M, B, Y;
ll ans;
ll solve(ll a, ll b)
{
    return (a*(a+1)*(b+1)/2+b*(b+1)*(a+1)/2);
}
int main()
{
    cin>>M>>B;
    for(int i=0; i<=B; i++)
    {
        Y = (B-i)*M;
        ans = max(ans, solve(i, Y));
    }
    cout<<ans<<endl;
}