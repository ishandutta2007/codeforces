#include<cstdio>
#include<algorithm>
using namespace std;
#define N 100010
int n,k;char s[N],t[N];
bool v[N*2];int d[N*2],q[N*2];
int main()
{
    scanf("%d%d%s%s",&n,&k,s,t);
    int le=0,ri=1;q[0]=0;
    while(le<ri)
    {
        int x=q[le++],y=x%n;
        if(y<d[x])continue;
        if(y+k>=n){puts("YES");return 0;}
        char *w=(x/n)?t:s;
        if(y!=0&&w[y]!='X'&&!v[x-1])
            v[x-1]=1,d[x-1]=d[x]+1,q[ri++]=x-1;
        if(w[y+1]!='X'&&!v[x+1])
            v[x+1]=1,d[x+1]=d[x]+1,q[ri++]=x+1;
        if(x<n)
            if(t[x+k]!='X'&&!v[n+x+k])
                v[n+x+k]=1,d[x+n+k]=d[x]+1,q[ri++]=x+n+k;
        if(x>=n)
            if(s[y+k]!='X'&&!v[x-n+k])
                v[x-n+k]=1,d[x-n+k]=d[x]+1,q[ri++]=x-n+k;
    }
    puts("NO");
    return 0;
}