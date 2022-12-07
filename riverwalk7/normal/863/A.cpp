#include <iostream>
using namespace std;
typedef long long ll;
ll x, y, cur;
void rev(ll a)
{
    cur *= 10;
    cur += (a%10);
    if(a>9)
    {
        rev(a/10);
    }
}
ll power(ll a, int b)
{
    if(b==0)
    {
        return 1;
    }
    else
    {
        return a * power(a, b-1);
    }
}
int main()
{
    cin>>x;
    rev(x);
    for(int i=0; i<=9; i++)
    {
        y = cur*(power(10, i));
        if(y==x)
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
}