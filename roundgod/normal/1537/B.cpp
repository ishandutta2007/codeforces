#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first 
#define S second
#define x1 daksida 
#define y1 daskdsia
#define x2 doakdos
#define y2 dakoda
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m,x,y;
ll get_dist(int x1,int y1,int x2,int y2)
{
    return max(x1-x2,x2-x1)+max(y1-y2,y2-y1);
}
int nx[4],ny[4];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&n,&m,&x,&y);
        printf("%d %d %d %d\n",1,1,n,m);
    }
    return 0;
}