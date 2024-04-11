#include <iostream>
#include <fstream>
#define MAXP 1001000
typedef long long ll;
ll a, b, p, x;
ll res[MAXP];
ll cur;
ll ans;
using namespace std;
int main()
{
    cin>>a>>b>>p>>x;
    res[p-1] = b;
    for(int i=p-2; i>=0; i--)
    {
        res[i] = res[i+1]*a;
        res[i] %= p;
    }
    for(int i=0; i<p-1; i++)
    {
        //must be res[i] mod p and i mod p-1
        ll cur = res[i]+p*(i-res[i]+2*p-2);
        cur = cur % (p*(p-1));
        ans += ((x-cur+(p*(p-1)))/(p*(p-1)));
    }
    cout<<ans<<endl;
}