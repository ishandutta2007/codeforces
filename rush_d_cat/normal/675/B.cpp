#include<iostream>
#include<math.h>
#include<stdio.h>
#include<cstring>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    __int64 a,b,c,d,n;
    __int64 num[7];
    cin>>n>>a>>b>>c>>d;
    num[0]=a+b;
    num[1]=a+c;
    num[2]=b+d;
    num[3]=c+d;
    sort(num,num+4);
    __int64 k=num[3]-num[0];
    if(k>=n) cout<<0<<endl;
    else cout<<n*(n-k)<<endl;
    return 0;
}