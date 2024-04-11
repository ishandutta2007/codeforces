#include<cstdio>
#include<cctype>
#include<vector>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=2000+19;
struct Solver
{
	vector<int> V;
	void Insert(int x) {V.push_back(x);}
	void Sort() {sort(V.begin(),V.end());}
	bool Empty() {return !V.size();}
	int Max() {return V[V.size()-1];}
	int Min() {return V[0];}
} A[10][2];
int Ans[10][10],Res,n,m,k,s,c,p;

int Calc(int a,int b)
{
	if (A[a][0].Empty()||A[b][0].Empty()) return -1;
	int tmp=max(max(abs(A[a][0].Max()-A[b][0].Min()),abs(A[a][0].Min()-A[b][0].Max())),
				max(abs(A[a][1].Max()-A[b][1].Min()),abs(A[a][1].Min()-A[b][1].Max())));
	return tmp;
}

int main()
{
	n=IN(),m=IN(),k=IN(),s=IN();
	For(i,1,n+1) For(j,1,m+1) c=IN(),A[c][0].Insert(i+j),A[c][1].Insert(i-j);
	For(i,1,k+1) A[i][0].Sort(),A[i][1].Sort();
	For(i,1,k+1) For(j,1,k+1) Ans[i][j]=Calc(i,j);
	c=IN();
	For(i,1,s) Res=max(Res,Ans[c][p=IN()]),c=p;
	printf("%d\n",Res);
}