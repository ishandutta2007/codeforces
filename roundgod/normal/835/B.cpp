#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int k;
char a[MAXN];
int num[10];
int main()
{
    scanf("%d",&k);
    scanf("%s",a);
    memset(num,0,sizeof(num));
    int x=strlen(a),s=0;
    for(int i=0;i<x;i++)
    {
       num[(int)(a[i]-48)]++;
       s+=(int)(a[i]-48);
    }
    if(s>=k)
    {
        printf("0\n");
        return 0;
    }
    int cnt=0,p=k-s;
    for(int i=0;i<9;i++)
    {
        if((9-i)*num[i]>=p)
        {
            cnt+=(p-1)/(9-i)+1;
            printf("%d\n",cnt);
            return 0;
        }
        else
        {
            cnt+=num[i];
            p-=(num[i]*(9-i));
        }
    }
    return 0;
}