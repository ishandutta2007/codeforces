#include<iostream>

using namespace std;

int main ()
{
    unsigned long long n,p,i=0;

    cin>>n;

    n++;

    p=n;

    if(p==1)
    {
        cout<<"0"<<endl;
        return 0;
    }

    if(p%2==0)
        cout<<p/2<<endl;
    else
        cout<<p<<endl;

    return 0;
}