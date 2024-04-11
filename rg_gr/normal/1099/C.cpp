#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#define int long long
inline int read()
{
    int num=0,f=1;char c=getchar();
    while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
    while(c>47&&c<58)num=(num<<3)+(num<<1)+(c^48),c=getchar();
    return num*f;
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
char a[100005];
char b[100005],c[100005];
int cnt;
inline int print(int x)
{
    if(x)putchar(x);
    return 0;
}
#define putchar print
signed main()
{
    scanf("%s",a);
    int n=strlen(a);
    //if(a[n-1]=='\r')n--;
    int q1=0,q2=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]=='?'){c[cnt]=1;q1++;}
        else if(a[i]=='*')q2++,c[cnt]=2;
        else b[++cnt]=a[i];
    }
    //printf("%d\n",n);
    int k=read();
    if(q2==0)
    {
        if(cnt-q1>k||cnt<k)printf("Impossible");
        else
        {
            int curl=n-q1;
            for(int i=1;i<=cnt;i++)
            {
                if(c[i]==0||curl==k)putchar(b[i]);
                else curl--;
            }
        }
    }
    else
    {
        int tot=n-q1-q2-q1-q2;
        if(tot>k)printf("Impossible");
        else
        {
            int D=k-tot;
            for(int i=1;i<=cnt;i++)
            {
                if(c[i]==1)continue;
                if(c[i]==0)putchar(b[i]);
                else
                {
                    for(int ii=0;ii<D;ii++)putchar(b[i]);
                    D=0;
                }
                
            }
        }
        
    }
    puts("");
}