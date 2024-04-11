#include<cstdio>
#include<vector>
using namespace std;

const int Maxn=1e5+19;
vector<int> Dis[Maxn];
int n,x,cnt,Ans[Maxn],Ans_[Maxn];

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&x),Dis[x].push_back(i);
	for (int i=1;i<Maxn;i++)
	{
		int Flag=1,tmp;
		if (Dis[i].size()==0) continue;
		if (Dis[i].size()==1) tmp=0;else tmp=Dis[i][1]-Dis[i][0];
		for (int j=2;j<Dis[i].size();j++)
			if (Dis[i][j]-Dis[i][j-1]!=tmp) {Flag=0;break;}
		if (Flag) Ans[cnt]=i,Ans_[cnt++]=tmp;
	}
	printf("%d\n",cnt);
	for (int i=0;i<cnt;i++) printf("%d %d\n",Ans[i],Ans_[i]);
}