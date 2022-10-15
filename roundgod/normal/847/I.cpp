#include<cmath>
#include<set>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define inf 1e9
#define maxn 255

using namespace std;
typedef long long ll;

struct point{
    ll x,y,z;
};

ll sum[maxn][maxn],p,q,a[maxn][maxn],v[maxn][maxn],n,m,cnt;
ll que[maxn*maxn],tmp,r2;
char s[maxn];
bool f[maxn][maxn];

void bfs(ll x0,ll y0,ll t,ll tt)
{
    ll l=0,r=1;
    ll x,y,z;
    v[x0][y0]=tt;
    que[0]=x0*m+y0;
    while (t&&l<r){
        r2=r;
        for (int i=l;i<r2;i++){
            tmp=que[i];x=tmp/m;y=tmp%m;
            sum[x][y]+=t;
            if (t>1){
                if (x>0&&v[x-1][y]!=tt&&f[x-1][y]){
                    que[r++]=(x-1)*m+y;
                    v[x-1][y]=tt;
                }
                if (x<n-1&&v[x+1][y]!=tt&&f[x+1][y]){
                    que[r++]=(x+1)*m+y;
                    v[x+1][y]=tt;
                }
                if (y>0&&v[x][y-1]!=tt&&f[x][y-1]){
                    que[r++]=x*m+y-1;
                    v[x][y-1]=tt;
                }
                if (y<m-1&&v[x][y+1]!=tt&&f[x][y+1]){
                    que[r++]=x*m+y+1;
                    v[x][y+1]=tt;
                }
            }
        }
        t/=2;l=r2;
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    scanf("%d%d",&p,&q);
    memset(f,true,sizeof(f));
    memset(v,0,sizeof(v));
    for (int i=0;i<n;i++)
    {
        scanf("%s",s);
        for (int j=0;j<m;j++)
            if (s[j]=='*') {f[i][j]=false;a[i][j]=0;}
            else if (s[j]=='.') a[i][j]=0;
            else a[i][j]=p*(s[j]-'A'+1);
    }
    cnt=0;
    memset(sum,0,sizeof(sum));
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
        if (a[i][j]){
            bfs(i,j,a[i][j],++cnt);
        }
    cnt=0;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if (sum[i][j]>q) cnt++;
        }
    }
    printf("%d\n",cnt);
    return 0;
}