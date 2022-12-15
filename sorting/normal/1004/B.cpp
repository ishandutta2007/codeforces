#include<iostream>

using namespace std;

int main ()
{
    int n,m,i;

    cin>>n>>m;

    for(i=0;i<m;i++)
    {
        int x,y;

        cin>>x>>y;
    }

    for(i=0;i<n/2;i++)
    {
        cout<<"01";
    }
    if(n%2==1)
        cout<<"0\n";

    return 0;
}