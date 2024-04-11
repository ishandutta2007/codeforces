#include<iostream>

using namespace std;

int main ()
{
    long long n,sum=0,i,x;
    bool y=false;

    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>x;
        sum+=x;
        if(x%2!=0)y=1;
    }

    if(sum%2!=0)cout<<"First"<<endl;
    else
    {
        if(y)cout<<"First"<<endl;
        else cout<<"Second"<<endl;
    }

    return 0;
}