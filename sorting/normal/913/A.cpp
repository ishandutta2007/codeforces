#include<iostream>

using namespace std;

int main ()
{
    long long n,m,i,x=1;

    cin>>n>>m;

    for(i=1;i<=n && x<=m;i++)
    {
        x*=2;
    }

    cout<<m%x<<endl;

    return 0;
}