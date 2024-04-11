#include <iostream>
#include <fstream>
#include <algorithm>
#define MAXN 200200
using namespace std;
typedef long long ll;
ll T, N, K;
ll x[MAXN];
void solve()
{
    cin>>N>>K;
    ll curgcd = 0;
    for(int i=0; i<N; i++)
    {
        cin>>x[i];
        if(i > 0)
        {
            curgcd = __gcd(curgcd, x[i]-x[i-1]);
        }
    }
    if(curgcd == 0 && K == x[0])
    {
        cout<<"YES"<<endl;
        return;
    }
    if(((K % curgcd) + curgcd) % curgcd == ((x[0] % curgcd)+curgcd) % curgcd)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
}
int main()
{
    cin>>T;
    for(int i=0; i<T; i++)
    {
        solve();
    }
}