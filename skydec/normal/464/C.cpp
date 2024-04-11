#include<stdio.h>
#include<cstring>
#define jsb 1000000007
#define MAXN 110000
using namespace std;
struct info
{
       int len,val;
       void mk(int x){len=10;val=x;}
       inline info operator +(info b)
       {
            info c;
            c.len=len*1ll*b.len%jsb;
            c.val=val*1ll*b.len%jsb;
            c.val=(c.val+b.val)%jsb;
            return c;
            }
}f[MAXN][10];
char str[MAXN];
char nmb[MAXN];
char fr[MAXN];
int st[MAXN];int n;
int main()
{
    scanf("%s",nmb+1);
    scanf("%d",&n);char q=getchar();st[1]=1;
    for(int i=1;i<=n;i++)
    {
            scanf("%c->",&fr[i]);
            char p=getchar();int k;
            for(k=st[i];p<='9'&&p>='0';k++,p=getchar())
            str[k]=p;
            //printf("%d\n",k);
            st[i+1]=k;
            }
    for(int i=0;i<=9;i++)f[n+1][i].mk(i);
    for(int i=n;i>=1;i--)
    {
            for(int p=0;p<=9;p++){f[i][p]=f[i+1][p];}
            int h=fr[i]-'0';
            f[i][h].val=0;f[i][h].len=1;
            for(int j=st[i];j<st[i+1];j++)
            f[i][h]=f[i][h]+f[i+1][str[j]-'0'];
            }
    info ans;ans.val=0;ans.len=1;
    int len=strlen(nmb+1);
    for(int i=1;i<=len;i++)ans=ans+f[1][nmb[i]-'0'];
    printf("%d\n",ans.val);
    return 0;
}