#include<iostream>
#include<map>
#include<math.h>
#include<stdio.h>
#include<cstring>
#include<string.h>
#include<algorithm>
using namespace std;
int n;
map<__int64,int> mp;
int main()
{
    cin>>n;__int64 tmp,m=0,sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>tmp;sum+=tmp;
        if(++mp[sum]>m) m=mp[sum];
    }
    cout<<n-m<<endl;
    return 0;
}