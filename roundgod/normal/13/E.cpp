#include<bits/stdc++.h>
#define MAXN 200005
using namespace std;
int n,m;
int a[MAXN],nxt[MAXN],step[MAXN];
int main()
{
    scanf("%d %d",&n,&m);
    int sz=(int)sqrt(n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++)
    {
        int num=i/sz,t=i,cnt=0;
        while(t/sz==num&&t<n)
        {
            t+=a[t];
            cnt++;
        }
        nxt[i]=t;
        step[i]=cnt;
    }
    for(int i=0;i<m;i++)
    {
        int q,x,y;
        scanf("%d",&q);
        if(q==1)
        {
            scanf("%d",&x);
            int k=x-1,s=0;
            while(true)
            {
                s+=step[k];
                if(nxt[k]>=n) break;
                k=nxt[k];
            }
            while(k+a[k]<n)
                k+=a[k];
            printf("%d %d\n",k+1,s);
        }
        else
        {
            scanf("%d %d",&x,&y);
            x--;
            a[x]=y;
            int num=x/sz,t=x,cnt=0;
            while(t/sz==num&&t<n)
            {
                t+=a[t];
                cnt++;
            }
            nxt[x]=t;
            step[x]=cnt;
            for(int j=x-1;j>=num*sz;j--)
                if((j+a[j])/sz==num&&(j+a[j]<n)) {step[j]=step[j+a[j]]+1; nxt[j]=nxt[j+a[j]];}
        }
    }
    return 0;
}