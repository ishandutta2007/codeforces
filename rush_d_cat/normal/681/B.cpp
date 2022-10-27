#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string.h>
using namespace std;
int main()
{
    int n;cin>>n;
    bool flag = false;
    for(int i=0;i<=n/1234567;i++)
    {
        for(int j=0;j<=n/123456;j++)
        {
            if((n-i*(1234567)-j*(123456))>=0&&(n-i*(1234567)-j*(123456))%1234==0) flag=true;
        }
    }
    if(flag) cout<<"YES";
    else cout<<"NO";
    return 0;
}