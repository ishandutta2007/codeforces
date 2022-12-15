#include<iostream>

using namespace std;

int main ()
{
    int n;

    cin>>n;

    if(n==1)
    {
        cout<<"0"<<endl;
        return 0;
    }

    cout<<(n+1)/2-1<<endl;

    return 0;
}