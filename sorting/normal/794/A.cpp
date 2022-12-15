#include<iostream>
#include<algorithm>

using namespace std;

int main ()
{
    int a,b,c,n,i,x,br=0;

    ios::sync_with_stdio(false);

    cin>>a>>b>>c>>n;

    for(i=0;i<n;i++)
    {
        cin>>x;

        if(b<x && x<c)br++;
    }

    cout<<br<<endl;

    return 0;
}