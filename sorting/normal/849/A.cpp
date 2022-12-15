#include<iostream>

using namespace std;

int n,a[10001];

int main  ()
{
    int i;

    cin>>n;

    for(i=0;i<n;i++)cin>>a[i];

    if(n%2!=0 && a[0]%2!=0 && a[n-1]%2!=0)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}