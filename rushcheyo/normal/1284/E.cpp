#include<stdio.h>
#include<string.h>
#include<algorithm>
#define MAXD 200010
typedef long long LL;
int N;
struct Point
{
    int x, y, a;
    Point(){}
    Point(int _x, int _y, int _a) : x(_x), y(_y), a(_a){}
    bool operator < (const Point &t) const
    {
        if(a == t.a) return (LL)y * t.x < (LL)x * t.y;
        return a < t.a;
    }
}p[MAXD],q[MAXD];
LL det(int x1, int y1, int x2, int y2)
{
    return (LL)x1 * y2 - (LL)x2 * y1;
}
void init()
{
    for(int i = 0; i < N; i ++)
    {
        int x = p[i].x, y = p[i].y, area;
        if(x >= 0 && y >= 0) area = 2;
        else if(x <= 0 && y <= 0) area = 0;
        else if(x > 0 && y < 0) area = 1;
        else area = 3;
        p[i] = Point(x, y, area);
    }
    std::sort(p, p + N);
    for(int i = 0; i < N; i ++) p[i + N] = p[i];
}
LL solve()
{
    LL ans = 0;
    int j = 0;
    for(int i = 0; i < N; i ++)
    {
        while(j < i + N && det(p[i].x, p[i].y, p[j].x, p[j].y) >= 0) ++ j;
        if(j - i >= 3) ans += (LL)(j - i - 2) * (j - i - 1) * (j - i - 3) / 6;
    }
	return ans;
}
int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;++i)scanf("%d%d",&q[i].x,&q[i].y);
	LL ans=1LL*N*(N-1)*(N-2)*(N-3)*(N-4)/24;
	--N;
	for(int i=0;i<=N;++i){
		for(int j=0,tot=0;j<N+1;++j)
			if(j!=i)p[tot++]=Point(q[j].y-q[i].y,q[j].x-q[i].x,0);
		init();
		ans-=solve();
	}
    printf("%lld\n",ans);
    return 0;
}