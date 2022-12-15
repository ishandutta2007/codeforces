#include<iostream>

using namespace std;

bool a[200];

int main ()
{
    int n,x,y;

    cin>>n>>x;

    for(int i=0;i<n;i++)
    {
        cin>>y;
        a[y]=1;
    }

    y=0;

    for(int i=0;i<x;i++)if(a[i]==1)y++;

    y=x-y;
    if(a[x]==1)y++;

    cout<<y<<endl;

    return 0;
}