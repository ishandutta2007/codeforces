#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

#define lowbit(x) ((x)&(-(x)))
#define sqr(x) ((x)*(x))
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PII;

#define maxn 1005

bool vis[maxn][maxn];
int n;

int main()
{
    scanf("%d",&n);
    
    memset(vis,false,sizeof(vis));
    int x=0,y=1%n;
    vis[0][y]=true;
    
    while (1)
    {
        int nx=x+y;
        if (nx>=n) nx-=n;
        int ny=y+1;
        if (ny>=n) ny-=n;
        
        if (vis[nx][ny]) break;
        x=nx;y=ny;
        vis[x][y]=true;
    }
    
    bool ok=true;
    for (int i=0;i<n && ok;++i)
    {
        bool fl=false;
        for (int j=0;j<n && !fl;++j)
        if (vis[i][j]) fl=true;
        if (!fl) ok=false;
    }
        
    if (ok) puts("YES");
    else puts("NO");
    return 0;
}