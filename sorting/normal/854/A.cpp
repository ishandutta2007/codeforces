#include<iostream>

using namespace std;

int gcd(int a,int b)
{
    if(b==0)
    {
        return a;
    }

    return gcd(b,a%b);
}

int main ()
{
    int n;

    cin>>n;

    for(int i=n/2;i>=1;i--)
    {
        if(gcd(i,n-i)==1)
        {
            cout<<i<<" "<<n-i<<endl;
            return 0;
        }
    }

    return 0;
}