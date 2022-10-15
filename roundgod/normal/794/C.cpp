#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MAXN 300005
using namespace std;
int n;
char a[MAXN];
int num1[MAXN],num2[MAXN],ans[MAXN];
bool cmp(int a,int b)
{
   return a>b;
}
int main()
{
    int n;
    memset(num1,0,sizeof(num1));
    memset(num2,0,sizeof(num2));
    scanf("%s",a);
    int len=strlen(a);
    for(int i=0;i<len;i++)
    {
      num1[i]=a[i]-64;
    }
    sort(num1,num1+len);
    scanf("%s",a);
    for(int i=0;i<len;i++)
    {
      num2[i]=a[i]-64;
    }
    sort(num2,num2+len,cmp);
    int head1,head2,head,tail1,tail2,tail;
    head1=0,head2=0,head=0;
    tail1=(len+1)/2-1;
    tail2=len-tail1-2;
    tail=len-1;
    while (head<=tail)
    {
        if(num2[head2]>num1[head1])
        {
            ans[head]=num1[head1];
            head++;
            head1++;
        }
        else
        {
            ans[tail]=num1[tail1];
            tail--;
            tail1--;
        }
        if(head>tail) break;
        if(num1[head1]<num2[head2])
        {
            ans[head]=num2[head2];
            head++;
            head2++;
        }
        else
        {
            ans[tail]=num2[tail2];
            tail--;
            tail2--;
        }
    }
    for(int i=0;i<len;i++)
    {
        printf("%c",ans[i]+64);
    }
    return 0;
}