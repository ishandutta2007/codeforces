#include<stdio.h>
#include<cstring>
using namespace std;
char str[1100000];
int n;
int max(int a,int b){if(a>b)return a;return b;}
int boy=0;
int ans=0;
int main()
{
    scanf("%s",str+1);
    n=strlen(str+1);int p=1;while(str[p]=='F'&&p<=n)p++;
    for(int i=p;i<=n;i++)
    if(str[i]=='F')ans=max(ans+1,boy);
    else boy++;
    printf("%d\n",ans);
    return 0;
}