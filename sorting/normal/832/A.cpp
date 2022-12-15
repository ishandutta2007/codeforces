#include<iostream>

using namespace std;

int main ()
{
    unsigned long long n,k,p;

    cin>>n>>k;

    p=n/k;

    if(p%2==0)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;

    return 0;
}