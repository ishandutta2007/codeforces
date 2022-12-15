#include<iostream>

using namespace std;

int main ()
{
    int n,m,curr=0,i,x,y;

    cin>>n>>m;

    for(i=0;i<n;i++)
    {
        cin>>x>>y;
        if(curr>=x && y>curr)curr=y;
    }

    if(curr>=m)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}