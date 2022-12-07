#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll x, y, l, r;
ll powerx[63]; ll powery[63];
int counterx, countery, counter;
ll totalinterval[4500];
ll ans;
int main()
{
    cin>>x>>y>>l>>r;
    powerx[0] = powery[0] = 1;
    for(int i=1; ; i++)
    {
        powerx[i] = powerx[i-1] * x;
        counterx++;
        if(powerx[i] > r/x)
        {
            break;
        }
    }
    for(int i=1; ; i++)
    {
        powery[i] = powery[i-1] * y;
        countery++;
        if(powery[i] > r/y)
        {
            break;
        }
    }
    for(int i=0; i<=counterx; i++)
    {
        for(int j=0; j<=countery; j++)
        {
            ++counter;
            totalinterval[counter] = powerx[i] + powery[j];
        }
    }
    totalinterval[counter+1] = l-1;
    totalinterval[counter+2] = r+1;
    counter += 2;
    sort(totalinterval, totalinterval + counter + 1);
    for(int i=0; i<=counter; i++)
    {
        if(totalinterval[i] >= (l-1) && totalinterval[i+1] <= (r+1))
        {
            ans = max(ans, totalinterval[i+1]-totalinterval[i]-1);
        }
    }
    cout<<ans<<endl;
}