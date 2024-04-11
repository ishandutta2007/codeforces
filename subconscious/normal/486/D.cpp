//#pragma comment(linker, "/STACK:102400000,102400000")
#include<cstdio>
#include<ctype.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdlib>
#include<stack>
#include<cmath>
#include<queue>
#include<set>
#include<map>
#include<ctime>
#include<string.h>
#include<string>
#include<sstream>
#include<bitset>
using namespace std;
#define ll long long
#define ull unsigned long long
#define eps 1e-11
#define NMAX 200005
#define MOD 1000000007
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define PI acos(-1)
template<class T>
inline void scan_d(T &ret)
{
    char c;
    int flag = 0;
    ret=0;
    while(((c=getchar())<'0'||c>'9')&&c!='-');
    if(c == '-')
    {
        flag = 1;
        c = getchar();
    }
    while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();
    if(flag) ret = -ret;
}
int a[2005],vis[2005];
int d,w,rt;
vector<int>v[2005];
ll dfs(int pos)
{
    vis[pos] = 1;
    int sz = v[pos].size();
    ll ret = 1;
    for(int i = 0; i < sz; i++) if(!vis[v[pos][i]])
    {
        int u = v[pos][i];
        if((w > a[u] && w - a[u] <= d) || (w == a[u] && u < rt))
        {
            ret = (ret+(ret*dfs(u))%MOD)%MOD;
        }
    }
    return ret;
}

int main()
{
#ifdef GLQ
    freopen("input.txt","r",stdin);
//    freopen("o4.txt","w",stdout);
#endif // GLQ
    int n;
    scanf("%d%d",&d,&n);
    for(int i = 1; i <= n; i++)
    {
        v[i].clear();
        scanf("%d",&a[i]);
    }
    for(int i = 1; i < n; i++)
    {
        int t1,t2;
        scanf("%d%d",&t1,&t2);
        v[t1].push_back(t2);
        v[t2].push_back(t1);
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++)
    {
        w = a[i]; rt = i;
        memset(vis,0,sizeof(vis));
        ans = (ans+dfs(i))%MOD;
    }
    printf("%I64d\n",ans);
    return 0;
}