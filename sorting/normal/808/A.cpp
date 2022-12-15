#include<iostream>

using namespace std;

int main ()
{
    int n,st=1,p;

    ios::sync_with_stdio(false);

    cin>>n;

    p=n;

    while(n>=10)
    {
        st*=10;
        n/=10;
    }

    n++;

    cout<<n*st-p<<endl;
}