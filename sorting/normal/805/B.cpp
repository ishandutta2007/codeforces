#include<iostream>

using namespace std;

int main ()
{
    int n,i;

    cin>>n;

    for(i=4;i<=n;i+=4)
    {
        cout<<"aabb";
    }
    n-=i-4;

    if(n==3)cout<<"aab";
    if(n==2)cout<<"aa";
    if(n==1)cout<<"a";

    cout<<endl;

    return 0;
}