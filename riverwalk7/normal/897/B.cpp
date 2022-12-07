#include <iostream>
#include <fstream>
using namespace std;
typedef long long ll;
ll K, P;
ll ans;
ll x[6];
ll c, q, z;
int main()
{
    cin>>K>>P;
    x[0] = 11;
    x[1] = 1001;
    x[2] = 100001;
    x[3] = 10000001;
    x[4] = 1000000001;
    x[5] = 100000000001;
    for(int i=1; i<=K; i++)
    {
        c = q = 0;
        z = i;
        while(z > 0)
        {
            c *= 10;
            c += (x[q]*(z%10));
            z = z/10;
            ++q;
        }
        ans = (ans+c)%P;
    }
    cout<<ans<<endl;
}