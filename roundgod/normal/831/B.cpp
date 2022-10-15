#include<bits/stdc++.h>
#define MAXN 30
#define MAXM 1005
using namespace std;
char s1[MAXN],s2[MAXN],s3[MAXM];
int a[MAXN];
int main()
{
    scanf("%s",s1);
    scanf("%s",s2);
    scanf("%s",s3);
    for(int i=0;i<26;i++)
      a[s1[i]-97]=s2[i]-97;
    for(int i=0;i<strlen(s3);i++)
    {
        if(s3[i]>=97&&s3[i]<=122)
        {
            printf("%c",a[s3[i]-97]+97);
        }
        else if(s3[i]>=65&&s3[i]<=90)
        {
            printf("%c",a[s3[i]-65]+65);
        }
        else printf("%c",s3[i]);
    }
    return 0;
}