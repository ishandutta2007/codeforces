#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
char str[MAXN];
int suf[MAXN],pre[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        scanf("%s",str+1);
        pre[0]=0;
        pre[1]=(str[1]=='L'?1:0);
        for(int i=2;i<=n;i++)
        {
            if(str[i]=='R') pre[i]=0;
            else if(str[i-1]=='L') pre[i]=1;
            else pre[i]=pre[i-2]+2;
        }
        suf[n]=0;
        suf[n-1]=(str[n]=='R'?1:0);
        for(int i=n-2;i>=0;i--)
        {
            if(str[i+1]=='L') suf[i]=0;
            else if(str[i+2]=='R') suf[i]=1;
            else suf[i]=suf[i+2]+2;
        }
        for(int i=0;i<=n;i++) printf("%d ",pre[i]+suf[i]+1);
        puts("");
    }
    return 0;
}