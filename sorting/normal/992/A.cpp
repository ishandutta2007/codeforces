#include<iostream>

using namespace std;

int a[200001];

int main ()
{
    int n,i,x,res=0;

    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>x;
        if(x!=0)a[x+100000]=1;
    }

    for(i=0;i<=200000;i++)
        res+=a[i];

    cout<<res<<endl;

    return 0;
}