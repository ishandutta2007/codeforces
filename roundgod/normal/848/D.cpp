#include<bits/stdc++.h>
#define MAXN 55
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,f[MAXN][MAXN],g[MAXN][MAXN];
int inv[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int get_comb(int x,int r)
{
    int res=1;
    add(x,r-1);
    for(int i=1;i<=r;i++)
    {
        res=1LL*res*x%MOD;
        dec(x,1);
        res=1LL*res*inv[i]%MOD;
    }
    return res;
}
int main()
{
    scanf("%d%d",&n,&m);
    inv[1]=1;
	for (int i=2;i<=50;i++)
		inv[i]=1LL*(MOD-MOD/i)*inv[MOD%i]%MOD;
    f[0][1]=1;
    for(int i=0;i<=n;i++)
    {
        for(int j=1;j<=i+1;j++)
        {
            for(int xi=0;xi<=i-1;xi++)
            {
                int yi=i-1-xi;
                for(int k=j;k<=xi+1;k++) add(g[i][j],1LL*f[xi][k]*f[yi][j]%MOD);
                for(int l=j+1;l<=yi+1;l++) add(g[i][j],1LL*f[xi][j]*f[yi][l]%MOD);
            }
            if(g[i][j])
            {
                for(int xi=n;xi>=0;xi--)
                    for(int xj=1;xj<=xi+1;xj++)
                        for(int t=1;xi+i*t<=n&&xj+j*t<=n+1;t++)
                            add(f[xi+i*t][xj+j*t],1LL*f[xi][xj]*get_comb(g[i][j],t)%MOD);
            }
        }
    }
    printf("%d\n",f[n][m]);
    return 0;
}