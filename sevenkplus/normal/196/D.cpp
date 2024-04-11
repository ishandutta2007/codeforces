#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define P 1000000007
#define N 400010
char s[N],t[N];int m,n,a[N],b[N],p[N];
bool F=0;
bool can(int x,int y)
{
    x++;
    if(x<y)return 1;
    int le=a[x]-a[x-y]*p[y],ri=b[x]-b[x-y];
    return le*p[x-y]!=ri;
}
void ff(int x,bool y)
{
    if(x==n){puts(t),F=1;return;}
    for(t[x]=(y?s[x]:'a');t[x]<='z';t[x]++)
    {
        a[x+1]=a[x]*P+t[x],
        b[x+1]=b[x]+t[x]*p[x];
        if(can(x,m)&&can(x,m+1))ff(x+1,y&&(t[x]==s[x]));
        if(F)return;
    }
    return;
}
int main()
{
    scanf("%d%s",&m,s),n=strlen(s);t[n]=0;
    int w=n-1;
    while(w>=0&&s[w]=='z')s[w]='a',w--;
    if(w<0){puts("Impossible");return 0;}
    s[w]++;
    p[0]=1;for(int i=1;i<N;i++)p[i]=p[i-1]*P;
    ff(0,1);
    if(!F)puts("Impossible");
    return 0;
}