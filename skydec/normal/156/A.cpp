#include<stdio.h>
#include<cstring>
#define MAXN 5005
using namespace std;
char a[MAXN],b[MAXN];
int lena,lenb;
int data[MAXN][MAXN];
int main()
{
    scanf("%s",a+1);lena=strlen(a+1);
    scanf("%s",b+1);lenb=strlen(b+1);
    for(int i=1;i<=lena;i++)a[i+2000]=a[i];
    for(int i=1;i<=2000;i++)a[i]='@';
    int ans=2100000000;
    memset(data,63,sizeof data);
    for(int j=0;j<=lena+2000;j++)data[j][0]=0;
    for(int j=1;j<=lenb;j++)
    for(int i=1;i<=lena+2000;i++)
    {
            if(a[i]==b[j])data[i][j]=data[i-1][j-1];
            else data[i][j]=data[i-1][j-1]+1;
            if(lenb-j+data[i][j]<ans)
            ans=lenb-j+data[i][j];
            }
    printf("%d\n",ans);
    return 0;
}