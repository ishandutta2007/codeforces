#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std ;
int main ()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    long long n;
    cin>>n;
    long long a=0;
    long long ret=0;
    long long x=n;
    while(x>=10)
    {
        a=a*10+9;
        ret+=9;
        x/=10;
    }
    long long y=n-a;
    while(y)
    {
        ret+=y%10;
        y/=10;
    }
    cout<<ret<<endl;

}