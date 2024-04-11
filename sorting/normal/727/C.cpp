#include<iostream>
#include<cstdio>

using namespace std;

#define fl fflush(stdout)

int arr[5001];

int main ()
{
    int n,a,b,c,i;

    cin>>n;

    cout<<"? 1 2"<<endl;
    fl;
    cin>>a;
    cout<<"? 1 3"<<endl;
    fl;
    cin>>b;
    cout<<"? 2 3"<<endl;
    fl;
    cin>>c;

    arr[1]=(a+b-c)/2;
    arr[2]=a-arr[1];
    arr[3]=b-arr[1];

    for(i=4;i<=n;i++)
    {
        cout<<"? 1 "<<i<<endl;
        fl;
        cin>>a;
        arr[i]=a-arr[1];
    }

    cout<<"!";

    for(i=1;i<=n;i++)
        cout<<" "<<arr[i];

    cout<<endl;
    fl;

    return 0;
}