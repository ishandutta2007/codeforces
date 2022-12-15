#include<iostream>

using namespace std;

int main ()
{
    int n,k;

    cin>>n>>k;

    if(k==0 || k==n)
    {
        cout<<"0 0"<<endl;
        return 0;
    }

    cout<<"1 ";
    cout<<min(n-k,k*2)<<endl;

    return 0;
}