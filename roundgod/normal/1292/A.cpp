#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,a[MAXN];
bool has[2][MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int dx[6]={1,1,1,-1,-1,-1};
int dy[6]={-1,0,1,-1,0,1};
int ans=0;
void flip(int x,int y)
{
    int cnt=0;
    for(int k=0;k<6;k++)
    {
        int nx=x+dx[k],ny=y+dy[k];
        if(nx>=0&&nx<=1&&ny>=0&&ny<=n-1&&has[nx][ny]) cnt++;
    }
    if(!has[x][y]) ans+=cnt; else ans-=cnt;
    has[x][y]=!has[x][y];
}
int main()
{
    scanf("%d%d",&n,&q);
    memset(has,false,sizeof(has));
    for(int i=0;i<q;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x--; y--;
        flip(x,y);
        if(ans||has[0][0]||has[1][n-1]) puts("No"); else puts("Yes");
    }
    return 0;
}