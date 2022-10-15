#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 5205
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define next dsjskjlfs
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int ans;
char s[MAXN];
char ss[MAXN][MAXN];
char str[MAXN];
int next[MAXN];
int sum[MAXN][MAXN];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int t=1;
        scanf("%s",s+1);
        for(int j=1;j<=n/4;j++)
        {
            int x;
            if(s[j]>='0'&&s[j]<='9') x=s[j]-'0'; else x=s[j]-'A'+10;
            for(int k=0;k<4;k++)
            {
                ss[i][t+k]='0'+(x&1);
                x>>=1;
            }
            reverse(ss[i]+t,ss[i]+t+4);
            t+=4;
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            sum[i][j]=sum[i-1][j]+(ss[i][j]=='1');
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            sum[i][j]=sum[i][j]+sum[i][j-1];
    for(int k=1;k<=n;k++)
    {
        if(n%k) continue;
        bool f=true;
        for(int i=1;i<=n;i+=n/k)
        {
            if(!f) break;
            for(int j=1;j<=n;j+=n/k)
            {
                int len=n/k;
                int res=sum[i+len-1][j+len-1]-sum[i-1][j+len-1]-sum[i+len-1][j-1]+sum[i-1][j-1];
                if(res!=0&&res!=len*len)
                {
                    f=false;
                    break;
                }
            }
        }
        if(f)
        {
            printf("%d\n",n/k);
            return 0;
        }
    }
    assert(0);//should not reach here
    return 0;
}