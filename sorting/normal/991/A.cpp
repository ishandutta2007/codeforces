#include<iostream>

using namespace std;

int main ()
{
    int a,b,c,n;

    cin>>a>>b>>c>>n;

    if(c>a || c>b || n-(a+b-c)<1)
        cout<<"-1"<<endl;
    else
        cout<<n-(a+b-c)<<endl;

    return 0;
}