#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#define MAXN 100
using namespace std;
int n,a[MAXN];
char str[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    scanf("\n");
    int flag=1;
    for(int i=0;i<n;i++)
    {
        gets(str);
        int x=strlen(str);
        int j=0,cnt=0,f=0;
        while(j<x)
        {
            if((str[j]=='a'||str[j]=='e'||str[j]=='i'||str[j]=='o'||str[j]=='u'||str[j]=='y')&&f==0)
            {
                cnt++;
            }
            j++;
        }
        if(cnt!=a[i]) flag=0;
    }
    if(flag==1) printf("YES"); else printf("NO");
    return 0;
}