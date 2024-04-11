#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
ll fib[61];
int c[MAXN];
int main()
{
    fib[0]=fib[1]=1;
    for(int i=2;i<=60;i++) fib[i]=fib[i-2]+fib[i-1];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&k);
        ll sum=0,s=0;
        for(int i=1;i<=k;i++) 
        {
            scanf("%d",&c[i]);
            sum+=c[i];
        }
        int id=-1;
        for(int i=0;i<=58;i++)
        {
            s+=fib[i];
            if(s==sum)
            {
                id=i;
                break;
            }
        }
        if(id==-1) {puts("NO"); continue;}
        bool f=true;
        int last=-1;
        for(int i=id;i>=0;i--)
        {
            int nid=-1,maxi=-INF;
            for(int j=1;j<=k;j++)
            {
                if(c[j]>maxi&&(j!=last))
                {
                    maxi=c[j];
                    nid=j;
                }
            }
            if(nid==last) {f=false; break;}
            if(maxi<fib[i]) {f=false; break;}
            //printf("fib=%d nid=%d\n",fib[i],nid);
            last=nid;
            c[nid]-=fib[i];
        }
        if(f) puts("YES"); else puts("NO");
    }
    return 0;
}