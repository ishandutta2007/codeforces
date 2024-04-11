#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[1000010];int n,p[1000010];
int main()
{
    scanf("%s",s),n=strlen(s);
    for(int i=0;i<n;i++)if(s[i]=='1')p[n-1-i]=1;
    for(int i=0,j;i<n+2;)
        if(!p[i])i++;else
        {
            j=i;while(p[j])j++;
            if(j-i>=2){p[i]=-1;for(int k=i+1;k<j;k++)p[k]=0;p[j]=1;}
            i=j;
        }
    int S=0;
    for(int i=0;i<n+2;i++)if(p[i]!=0)S++;
    printf("%d\n",S);
    for(int i=0;i<n+2;i++)if(p[i]!=0)
        if(p[i]>0)printf("+2^%d\n",i);
        else printf("-2^%d\n",i);
    return 0;
}