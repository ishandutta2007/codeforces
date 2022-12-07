#include <iostream>
#include <fstream>
using namespace std;
typedef long long ll;
int main()
{
    ll l, r, x, y, k;
    cin>>l>>r>>x>>y>>k;
    for(ll i = x; i <= y; i++)
    {
        if((k*i)<=r&&(k*i)>=l)
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
}