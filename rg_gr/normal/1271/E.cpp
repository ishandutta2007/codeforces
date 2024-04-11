#include <stdio.h>
#include <string.h> 
#include <queue>
#define int unsigned long long
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){c=getchar();}
	while(c>47&&c<58)num=num*10+(c^48),c=getchar();
	return num;
}
inline int min(int a,int b)
{
    return a<b?a:b;
}
int check(int a,int n)
{
    if(a==n)return 1;
    int ans=0,i=1;
    while(a<=n)
    {
        ans+=min(i,n-a+1);
        a<<=1;
        i<<=1;
    }
    return ans;
    //if(a&1)return ans;
}
int chack(int a,int n)
{
    if(a==n)return 1;
    int ans=0,i=1,p=a;
    while(a<=n)
    {
        ans+=min(i,n-a+1);
        a<<=1;
        i<<=1;
    }
    return ans+check(p+1,n);
    //if(a&1)return ans;
}
/*    if(a==n)return 1;
    if(a+a>=n)
    {
        if(a+a==n)
        {
            if(a&1)return 2;
            else return 3;
        }
        else return 2-(a&1);
    }
    int p=a,i=0;
    while(p+p+1<=n)p=p+p,i=i+1;
    int u=p+p;
    int v=(a+1<<(i))-1;
    v=v>n?n:v;
    u=min(u,n);
    int pppppp=0;
    if(a&1);else pppppp=chack(a+1,n);
    return printf("f(%llu) = %llu\n",a,pppppp+(1ull<<i+1)+u-v),pppppp+(1ull<<i+1)+u-v;
}
    int i=1,p=a,o=1;
    while((p<<2)-1<=n)p<<=1,i<<=1,o+=i;
    int yyy=0;
    if(a&1);else yyy=chack(a+1,n);
    int opo=2;
    //if((a<<2)-1>n)opo=2;
    return printf("%llu %llu\n",a,o+min(i*opo*(a+1)-1,n)-p-p+1+yyy),o+min(i*opo*(a+1)-1,n)-p-p+1+yyy;
}*/
signed main()
{
    int n=read(),k=read();
    int L=0,R=n>>1,ans=0;if(n&1);else R--;
    while(L<=R)
    {
        int m=L+R>>1;
        //printf("%llu = m\n",m+m+1);
        if(check(m+m+1,n)>=k)ans=m,L=m+1;
        else R=m-1;
    }
    int anss=0;L=1,R=n>>1;
    while(L<=R)
    {
        int m=L+R>>1;
        //printf("%llu = m\n",m+m);
        if(chack(m+m,n)>=k)anss=m,L=m+1;
        else R=m-1;
    }
    anss*=2,ans*=2,ans++;
    printf("%llu\n",ans>anss?ans:anss);
}