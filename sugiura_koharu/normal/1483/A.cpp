#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> v[100005];
int cnt[100005],ans[100005];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		int qwq=(m+1)/2,F=0;
		for(int i=1;i<=n;i++) cnt[i]=0;
		for(int i=1;i<=m;i++)
		{
			int s=0;
			scanf("%d",&s);
			v[i].clear();
			while(s--)
			{
				int t;
				scanf("%d",&t);
				v[i].push_back(t);
			}
			if(v[i].size()==1)
			{
				if(++cnt[v[i][0]]>qwq) F=1;
				ans[i]=v[i][0];
				v[i].clear();
			}
		}
		for(int i=1;i<=m;i++)
		{
			int flag=0;
			for(auto t:v[i])
			{
				if(cnt[t]<qwq)
				{
					ans[i]=t;
					++cnt[t];
					flag=1;
					break;
				}
			}
			if(!flag&&v[i].size())
			{
				F=1;
				break;
			}
		}
		if(F)
		{
			puts("NO");
		}
		else
		{
			puts("YES");
			for(int i=1;i<=m;i++)
				printf("%d ",ans[i]);
			puts("");
		}
	}
	return 0;
}