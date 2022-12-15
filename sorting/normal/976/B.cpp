#include<iostream>

using namespace std;

int main ()
{
    long long n,m,k;

    cin>>n>>m>>k;

    if(k<=n-1)
    {
        cout<<k+1<<" 1"<<endl;
        return 0;
    }

    cout<<n-(k-n)/(m-1)<<" ";
    if((k-n)/(m-1)%2==0)
    {
        cout<<(k-n)%(m-1)+2<<endl;
    }
    else
    {
        cout<<m-(k-n)%(m-1)<<endl;
    }

    return 0;
}