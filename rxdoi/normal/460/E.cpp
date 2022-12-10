#include<cstdio>
#include<cctype>
#include<vector>
#include<cstring>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define Pb push_back
using namespace std;

int sqr(int x) {return x*x;}
int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=10;
struct Point
{
	int x,y;
	bool operator < (const Point& B) const {return sqr(x)+sqr(y)>sqr(B.x)+sqr(B.y);}
};
vector<Point> V;
int Ans[N],cur[N],n,m,r,Max=-1;

void DFS(int x,int c)
{
	if (x==n)
	{
		if (*cur>*Ans) memcpy(Ans,cur,sizeof(cur));
		return;
	}
	For(i,c,m)
	{
		int tmp=0;
		For(j,1,x+1) tmp+=sqr(V[i].x-V[cur[j]].x)+sqr(V[i].y-V[cur[j]].y);
		cur[x+1]=i,*cur+=tmp;
		DFS(x+1,i),*cur-=tmp;
	}
}

int main()
{
	*Ans=-1;
	n=IN(),r=IN();
	for (int i=-r;i<=r;i++)
		for (int j=-r;j<=r;j++)
			if (i*i+j*j<=r*r) V.Pb((Point){i,j});
	sort(V.begin(),V.end());
	m=min(int(V.size()),18);
	DFS(0,0);
	printf("%d\n",*Ans);
	For(i,1,n+1) printf("%d %d\n",V[Ans[i]].x,V[Ans[i]].y);puts("");
}