#include<stdio.h>
#include<cstring>
#define MAXN 2300000
using namespace std;
int go[MAXN][26];
int n,k;int tot=1;
char str[1600];
bool wei[28];
char pang[28];
int main()
{
    scanf("%s",str+1);n=strlen(str+1);
    scanf("%s",pang);for(int i=0;i<26;i++)wei[i]=pang[i]-'0';
    scanf("%d",&k);
    for(int i=1;i<=n;i++)
    {
            int now=1;
            int we=0;
            for(int j=i;j<=n;j++)
            {
                    we+=1-wei[str[j]-'a'];
                    if(we>k)break;
                    if(!go[now][str[j]-'a'])go[now][str[j]-'a']=++tot;
                    now=go[now][str[j]-'a'];
                    }
                    }
    printf("%d\n",tot-1);
    return 0;
}