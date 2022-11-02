#include<bits/stdc++.h>
#define N 100005
using namespace std;
int n,m,w,ans;
struct qwq
{
	int key,val;
	friend bool operator <(qwq a,qwq b)
	{return a.key>b.key;}
};
set<qwq>S[N],T[N];
set<qwq>::iterator it,tp;
inline void ins(int x,int y,int z)
{S[x].insert({y,z}),T[x].insert({-y,z});}
int u,v;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
	ins(i,-1,0);
    while(m--)
	{
		scanf("%d%d%d",&u,&v,&w);
		it=S[u].upper_bound({w,0});
		register int val=it->val+1;
		for(;;)
		{
			tp=T[v].lower_bound({-w,0});
			if(tp==T[v].end()||tp->val>val)break;
			S[v].erase(S[v].lower_bound({-tp->key,0}));
			T[v].erase(tp);
		}
		if(S[v].lower_bound({w,0})->val<val)
		ins(v,w,val);
	}
	for(int i=1;i<=n;i++)
	ans=max(ans,S[i].lower_bound({100000,0})->val);
	printf("%d",ans);
}