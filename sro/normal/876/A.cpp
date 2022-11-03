#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

long long path[3],n,minans=1000000007,num0=1e9,num1=1e9;


int main()
{
    scanf("%I64d%I64d%I64d%I64d",&n,path,path+1,path+2);
    int cur,ans;
    if(n==1)return puts("0"),0;
    for(int i=1;i<=1;i++)
        for(int j=2;j<=3;j++)
            for(int k=1;k<=3;k++)
                if(j!=k&&num0+num1*(n-2)>path[i+j-3]+path[j+k-3]*(n-2))
                {
                    num0=path[i+j-3];
                    num1=path[j+k-3];
                }
    printf("%d\n",num0+num1*(n-2));
    return 0;
}