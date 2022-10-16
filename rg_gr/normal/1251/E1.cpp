#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#define int long long
inline long long read()
{
	long long num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>=48&&c<=57)num=num*10+(c^48),c=getchar();
	return num*f;
}
int *a[200005],cnt[200005];
int t[200005],c[200005],b[200005];
#define ms(x) memset(x,0,sizeof(int)*(n+3))
signed main()
{
    int T=read();
    while(T--)
    {
        int n=read(),ans=0;
        ms(t);ms(cnt);
        for(int i=0;i<n;i++)c[i]=read(),b[i]=read(),t[c[i]]++;
        for(int i=0;i<n;i++)a[i]=new int[t[i]];
        for(int i=0;i<n;i++)a[c[i]][cnt[c[i]]++]=b[i];
        std::priority_queue<int,std::vector<int>,std::greater<int> >q;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<t[i];j++)q.push(a[i][j]);
            while(q.size()>n-i)ans+=q.top(),q.pop();
        }
        printf("%lld\n",ans);
        for(int i=0;i<n;i++)delete[] a[i];
    }
	return 0;
}