#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long long num[1000000];
long long num2[1000000];
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int x,y;
        cin>>x>>y;
        num[x+y]++,num2[x-y+1000]++;
    }
    long long ans=0;
    for (int i=0;i<=100000;i++)
    {
        ans+=num[i]*(num[i]-1)/2+num2[i]*(num2[i]-1)/2;
    }
    cout<<ans<<endl;
}