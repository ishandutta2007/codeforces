#include<iostream>

using namespace std;

#define endl "\n"

int main ()
{
    int n,i;

    ios::sync_with_stdio(false);

    cin>>n;

    if(n<6)cout<<"-1"<<endl;
    else
    {
        cout<<"1 2"<<endl;
        cout<<"2 3"<<endl;
        cout<<"2 4"<<endl;
        for(i=5;i<=n;i++)
            cout<<"1 "<<i<<endl;
    }

    for(i=1;i<n;i++)
        cout<<i<<" "<<i+1<<endl;

    return 0;
}