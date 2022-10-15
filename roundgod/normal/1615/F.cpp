#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n;
char s[MAXN],t[MAXN];
int ways[MAXN][2*MAXN],dp[MAXN][2*MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        scanf("%s",s+1); scanf("%s",t+1);
        for(int i=1;i<=n;i++)
            for(int j=-n;j<=n;j++)
                dp[i][j+n]=ways[i][j+n]=0;
        for(int i=2;i<=n;i+=2)
        {
            if(s[i]!='?') s[i]='0'+'1'-s[i];
            if(t[i]!='?') t[i]='0'+'1'-t[i]; 
        }
        ways[0][n]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=-i;j<=i;j++)
            {
                if(!ways[i][j+n]) continue;
                for(int x=0;x<2;x++)
                {
                    if(s[i+1]!='?'&&s[i+1]!='0'+x) continue;
                    for(int y=0;y<2;y++)
                    {
                        if(t[i+1]!='?'&&t[i+1]!='0'+y) continue;
                        int nj=j+x-y;
                        add(ways[i+1][nj+n],ways[i][j+n]);
                        add(dp[i+1][nj+n],dp[i][j+n]);
                        add(dp[i+1][nj+n],1LL*ways[i][j+n]*(max(-nj,nj))%MOD);
                    }
                }
            }
        }
        printf("%d\n",dp[n][n]);
    }
    return 0;
}