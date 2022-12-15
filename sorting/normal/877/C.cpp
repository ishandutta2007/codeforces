#include<iostream>

using namespace std;

int n;

int main ()
{
    int m=0,i;

    cin>>n;

    if(n==2)
    {
        cout<<"3"<<endl;
        cout<<"2 1 2"<<endl;
        return 0;
    }

    cout<<n+n/2<<endl;
    cout<<"2";
    for(i=4;i<=n;i+=2)cout<<" "<<i;
    for(i=1;i<=n;i+=2)cout<<" "<<i;
    for(i=2;i<=n;i+=2)cout<<" "<<i;

    cout<<endl;

    return 0;
}