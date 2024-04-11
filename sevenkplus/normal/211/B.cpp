#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 1000010
char s[N],t[33];int w[26],u[26],n,A[N*26],L;
bool cmp(int x,int y){return w[x]>w[y];}
int main()
{
    scanf("%s",s);n=strlen(s);
    memset(w,-1,sizeof w);
    for(int i=0;i<26;i++)u[i]=i;
    for(int i=0;i<n;i++)
    {
        w[s[i]-'a']=i;
        sort(u,u+26,cmp);
        int ms=0;
        for(int j=0;j<26;j++)
            if(w[u[j]]!=-1&&(i==n-1||s[i+1]!='a'+u[j]))
                {ms|=(1<<u[j]);A[L++]=ms;}else break;
    }
    sort(A,A+L);
    int _;scanf("%d",&_);
    while(_--)
    {
        scanf("%s",t);
        int m=strlen(t),ms=0;
        for(int i=0;i<m;i++)
            ms^=(1<<(t[i]-'a'));
        int le=lower_bound(A,A+L,ms)-A,ri=lower_bound(A,A+L,ms+1)-A;
        printf("%d\n",ri-le);
    }
    return 0;
}