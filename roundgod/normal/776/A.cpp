#include<bits/stdc++.h>
#define MAXN 30
using namespace std;
char str[MAXN];
char str1[MAXN];
char str2[MAXN];
bool cmp(char x[],char y[])
{
    int a=strlen(x),b=strlen(y);
    if(a!=b) return false;
    for(int i=0;i<a;i++)
        if(x[i]!=y[i]) return false;
    return true;
}
int n;
int main()
{
    gets(str);
    printf("%s\n",str);
    int l=strlen(str);
    int j=0,k=0;
    while(str[k]!=' ')
    {
        str1[k]=str[k];
        k++;
    }
    j=k+1;
    k=0;
    while(j<l)
    {
        str2[k]=str[j];
        j++;
        k++;
    }
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++)
    {
        gets(str);
        l=strlen(str);
        char x[MAXN]="",y[MAXN]="";
        k=0;
        while(str[k]!=' ')
        {
            x[k]=str[k];
            k++;
        }
        j=k+1;
        k=0;
        while(j<l)
        {
            y[k]=str[j];
            j++;
            k++;
        }
        if(cmp(x,str1)) strcpy(str1,y); else strcpy(str2,y);
        printf("%s %s\n",str1,str2);
    }
    return 0;
}