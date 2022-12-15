#include<iostream>

using namespace std;

long long fact(long long x)
{
    long long res=1,i;

    for(i=1;i<=x;i++)
        res*=i;

    return res;
}

int main ()
{
    long long a,b;

    cin>>a>>b;

    cout<<fact(min(a,b))<<endl;

    return 0;
}