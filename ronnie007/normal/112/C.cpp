#include<iostream>
#include<stdio.h>
using namespace std;

int main()
    {
    long long sm=0;
    int n;
    int i;
    long long x,y;
    cin>>n>>x>>y;
    if(y<n){cout<<"-1\n";return 0;}
    sm=(y-n+1)*(y-n+1)+(n-1);
    if(sm>=x)
        {
        for(i=0;i<n-1;i++)cout<<"1\n";
        cout<<y-n+1<<"\n";
        }
    else printf("-1\n");
    return 0;
    }