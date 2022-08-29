#include<stdio.h>
#include<cstring>
using namespace std;
int t[27];
char str[1005];int k;int len=0;
int main()
{
    scanf("%d",&k);
    scanf("%s",str+1);len=strlen(str+1);
    for(int i=1;i<=len;i++)t[str[i]-'a'+1]++;
    for(int i=1;i<=26;i++)
    if(t[i]%k!=0)
    {
                 printf("-1\n");
                 return 0;
                 }
    for(int i=1;i<=k;i++)
    for(int j=1;j<=26;j++)
    for(int p=1;p<=t[j]/k;p++)
    putchar(j+'a'-1);
    return 0;
}