#include<cstdio>
#include<vector>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

const int N=200+19;
vector<int> V[N];
int n,t,Ca,Cb,x,f,Ans[N];

int main()
{
	scanf("%d",&n);n*=2;
	For(i,0,n) scanf("%d",&x),V[x].push_back(i);
	For(i,10,100)
	{
		if ((t=V[i].size())>=2) Ca++,Cb++;else continue;
		for (;t>=2;t-=2)
			Ans[V[i].back()]=1,V[i].pop_back(),
			Ans[V[i].back()]=2,V[i].pop_back();
		if (t) Ans[V[i].back()]=f?1:2,V[i].pop_back(),f^=1;
	}
	For(i,10,100) if (V[i].size()) Ans[V[i].back()]=f?(Ca++,1):(Cb++,2),f^=1;
	printf("%d\n",Ca*Cb);
	For(i,0,n) printf("%d ",Ans[i]);puts("");
}