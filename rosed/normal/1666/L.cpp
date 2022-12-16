#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define y1 zmakioi
const int N=5e5+10;
int n,m,s;
vector<int> eg[N];
queue<int> q;
int pre[N];
int qwq[N];
int st[N][2],top[2];
inline void spfa()
{
	pre[s]=-1;
	for(int t:eg[s])
	{
		pre[t]=s;
		qwq[t]=t;
		q.push(t);
	}
	while(!q.empty())
	{
		int now=q.front();q.pop();
		for(int t:eg[now])
		{
			if(!pre[t])
			{
				pre[t]=now;
				qwq[t]=qwq[now];
				q.push(t);
			}
			else if(qwq[t]!=qwq[now])
			{
				int x=t;
				while(x>0)
				{
					st[++top[0]][0]=x;
					x=pre[x];
				}
				st[++top[1]][1]=t;
				x=now;
				while(x>0)
				{
					st[++top[1]][1]=x;
					x=pre[x];
				}
				return;
			}
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=m;++i)
	{
		int x,y;
		cin>>x>>y;
		if(y!=s) eg[x].emplace_back(y);
	}
	spfa();
	if(!top[0])
	{
		cout<<"Impossible\n";
	}
	else
	{
		cout<<"Possible\n";
		for(int k=0;k<2;++k)
		{
			cout<<top[k]<<'\n';
			for(int i=top[k];i;--i) cout<<st[i][k]<<" \n"[i==1];
		}
	}
	return 0;
}
/*
6 7 1
1 2
2 3
3 4
4 5
5 1
1 6
6 1


*/