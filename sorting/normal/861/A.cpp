#include<iostream>

using namespace std;

int main ()
{
    long long n,k,i;

    cin>>n>>k;

    for(i=0;i<k && n%2==0;i++)n/=2;
    for(i=0;i<k && n%5==0;i++)n/=5;

    cout<<n;
    for(i=0;i<k;i++)cout<<"0";
    cout<<endl;

    return 0;
}