#include<iostream>
#include<stdio.h>
using namespace std;


int main()
    {
    int n;
    long long d;
    long long ans=0;
    cin>>d;
    scanf("%d",&n);
    int i;
    int x;
    for(i=0;i<n-1;i++)
        {
        scanf("%d",&x);
        ans+=(d-x);
        }
    cin>>x;
    cout<<ans<<"\n";
    return 0;
    }