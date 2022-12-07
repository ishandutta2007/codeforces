#include <iostream>
#include <fstream>
using namespace std;
typedef long long ll;
int main()
{
    ll a, b;
    ll cur = 1; ll cur2;
    cin>>a>>b;
    if((b-a)>10)
    {
        cout<<0<<endl;
        return 0;
    }
    else
    {
        for(ll x = a+1; x <= b; x++)
        {
            cur2 = x % 10;
            cur *= cur2;
            cur %= 10;
        }
        cout<<cur<<endl;
    }
}