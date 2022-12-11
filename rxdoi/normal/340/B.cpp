#include<cstdio>
using namespace std;

const int Maxn=300+19,oo=(1<<30)-1;
struct Point {int x,y;} A[Maxn];
typedef Point Vector;
int n;double Ans=0.;

Vector operator - (Point A,Point B) {return (Vector){B.x-A.x,B.y-A.y};}
inline int Cross(Vector A,Vector B) {return A.x*B.y-A.y*B.x;}
inline int max(int a,int b) {return a>b?a:b;}

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d%d",&A[i].x,&A[i].y);
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			if (i!=j)
			{
				int MaxL=-oo,MaxR=-oo;
				for (int k=0;k<n;k++)
				if (i!=k&&j!=k)
				{
					int tmp=Cross(A[j]-A[i],A[k]-A[i]);
					if (tmp>0) MaxL=max(MaxL,tmp);
					if (tmp<0) MaxR=max(MaxR,-tmp);
				}
				if (MaxL+MaxR>Ans) Ans=double(MaxL+MaxR);
			}
	printf("%.6lf\n",Ans/2.);
	return 0;
}