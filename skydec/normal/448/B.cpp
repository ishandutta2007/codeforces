#include<stdio.h>
#include<cstring>
#define MAXN 105
using namespace std;
char str[MAXN];
char str2[MAXN];
int len1,len2;
bool checkAUT()
{
     int i=1;int j=1;
     for(int i=1;i<=len1;i++)
     if(str[i]==str2[j])j++;
     return j>len2;
}
int a[27];
int b[27];
bool checkSWAP()
{
     for(int i=1;i<=26;i++)if(a[i]!=b[i])return false;
     return true;
}
bool checkSA()
{
     for(int i=1;i<=26;i++)if(a[i]<b[i])return false;
     return true;
}
int main()
{
    scanf("%s",str+1);len1=strlen(str+1);
    scanf("%s",str2+1);len2=strlen(str2+1);
    for(int i=1;i<=len1;i++)a[str[i]-'a'+1]++;
    for(int i=1;i<=len2;i++)b[str2[i]-'a'+1]++;
    if(checkSWAP())
    {
                   printf("array\n");
                   return 0;
                   }
    if(checkAUT())
    {
                  printf("automaton\n");
                  return 0;
                  }
    if(checkSA())
    {
                 printf("both\n");
                 return 0;
                 }
    printf("need tree\n");
    return 0;
}