#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const string num[10]={"... ...","  .  . ",". ... .",". .. .."," ... . ",".. . ..",".. ....",". .  . ",".......",".... .."};
int dl[10][10],pl[10];
char ss[200010];int s[200010],*t,u[100010],p[100010],q[100010];int n;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            for(int k=0;k<7;k++)
                if(num[i][k]==num[j][k]&&num[i][k]=='.')dl[i][j]++;
    for(int i=0;i<10;i++)
        for(int k=0;k<7;k++)if(num[i][k]=='.')pl[i]++;
    scanf("%s",ss);n=strlen(ss)/2;t=s+n;
    for(int i=0;i<n*2;i++)s[i]=ss[i]-'0';
    //FIRST
    for(int i=n-1;i>=0;i--)
    {
        for(int j=t[i]+1;j<=9;j++)
            if(dl[j][s[i]]-dl[s[i]][t[i]]+p[i+1]>0)
            {
                int S=dl[j][s[i]]-dl[s[i]][t[i]];
                for(int k=0;k<n;k++)putchar('0'+s[k]);
                for(int k=0;k<i;k++)putchar('0'+t[k]);
                putchar('0'+j);
                for(int k=i+1;k<n;k++)
                    for(int j=0;j<10;j++)
                        if(S+dl[j][s[k]]-dl[s[k]][t[k]]+p[k+1]>0){S=S+dl[j][s[k]]-dl[s[k]][t[k]];putchar('0'+j);break;}
                puts("");
                return 0;
            }
        p[i]=p[i+1]+pl[s[i]]-dl[s[i]][t[i]];
    }
    //SECOND
    p[0]=0;for(int i=1;i<n;i++)p[i]=p[i-1]+pl[s[i-1]]-dl[s[i-1]][t[i-1]];
    for(int i=n-1;i>=0;i--)
    {
        for(int j=s[i]+1;j<=9;j++)
            if(p[i]+pl[j]-dl[s[i]][t[i]]+q[i+1]>0)
            {
                int S=p[i]+pl[j]-dl[s[i]][t[i]];
                for(int k=0;k<i;k++)putchar('0'+s[k]),u[k]=s[k];
                putchar('0'+j),u[i]=j;
                for(int k=i+1;k<n;k++)
                    for(int j=0;j<10;j++)
                        if(S+pl[j]-dl[s[k]][t[k]]+q[k+1]>0){S=S+pl[j]-dl[s[k]][t[k]];putchar('0'+j),u[k]=j;break;}
                for(int k=0;k<n;k++)
                    for(int j=0;j<10;j++)
                        if(S+dl[j][u[k]]-pl[u[k]]>0)
                        {
                            S=S+dl[j][u[k]]-pl[u[k]];
                            putchar('0'+j);break;
                        }
                puts("");
                return 0;
            }
        q[i]=q[i+1]+7-dl[s[i]][t[i]];
    }
    puts("-1");
    return 0;
}