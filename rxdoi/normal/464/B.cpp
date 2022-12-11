#include<cstdio>
#include<algorithm>
using namespace std;

typedef long long LL;
struct Point {LL x,y,z;} A[8],B[8];
int OK;

inline LL sqr(LL x) {return x*x;}
inline LL Dis(Point A,Point B)
{
	return sqr(A.x-B.x)+sqr(A.y-B.y)+sqr(A.z-B.z);
}

inline void check()
{
	for (int i=0;i<8;i++)
	{
		LL D[8];
		for (int j=0;j<8;j++) D[j]=Dis(A[i],A[j]);
		sort(D,D+8);
		if (D[1]==0) return;
		if (D[1]!=D[2]||D[2]!=D[3]) return;
		if (D[4]!=D[5]||D[5]!=D[6]) return;
		if (2*D[1]!=D[4]) return;
		if (3*D[1]!=D[7]) return;
	}
	puts("YES");
	for (int i=0;i<8;i++) printf("%I64d %I64d %I64d\n",A[i].x,A[i].y,A[i].z);
	OK=1;
}
inline void DFS(int x)
{
	if (OK) return;
	if (x==8) {check();return;}
	A[x]=(Point){B[x].x,B[x].y,B[x].z};DFS(x+1);
	A[x]=(Point){B[x].x,B[x].z,B[x].y};DFS(x+1);
	A[x]=(Point){B[x].y,B[x].x,B[x].z};DFS(x+1);
	A[x]=(Point){B[x].y,B[x].z,B[x].x};DFS(x+1);
	A[x]=(Point){B[x].z,B[x].x,B[x].y};DFS(x+1);
	A[x]=(Point){B[x].z,B[x].y,B[x].x};DFS(x+1);
}

int main()
{
	for (int i=0;i<8;i++) scanf("%I64d%I64d%I64d",&B[i].x,&B[i].y,&B[i].z);
	A[0]=B[0];
	DFS(1);
	if (!OK) puts("NO");
}