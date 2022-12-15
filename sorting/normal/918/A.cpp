#include<iostream>

using namespace std;

bool check(int x)
{
    int f1=1,f2=2,p;

    if(x==1 || x==2)return 1;

    while(f2<x)
    {
        p=f2;
        f2=f1+f2;
        f1=p;
    }

    if(x==f2)return 1;

    return 0;
}

int main ()
{
    int n,i;

    cin>>n;

    for(i=1;i<=n;i++)
    {
        if(check(i))cout<<"O";
        else cout<<"o";
    }

    cout<<endl;

    return 0;
}