#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>

void read(){}
template<class ...T> void read(int *x,T... Args)
{
	char c=*x=0;
	for(c=getchar();!isdigit(c);c=getchar());
	for(;isdigit(c);c=getchar())*x=*x*10+(c^48);
	read(Args...);
}

namespace kk
{
	inline bool check_max(int a,int &b){return a>b?b=a,1:0;}

	const int N=505,M=10000000,INF=1000000007;

	int totpoints,S,T;

	struct maxflow
	{
		int begin[N*10],next[M],to[M],w[M],c[M];

		int e;
	
		maxflow(){e=1;}

		void add(int x,int y,int z,int cost,bool k=1)
		{
			to[++e]=y;
			next[e]=begin[x];
			begin[x]=e;
			w[e]=z;
			c[e]=cost;
			if(k)add(y,x,0,-cost,0);
		}

		int pre[N*10],dis[N*10];
		bool bfs()
		{
			static std::queue<int> Q;

			while(!Q.empty())Q.pop();
			for(int i=1;i<=totpoints;i++)dis[i]=-INF;
			pre[S]=dis[S]=0,Q.push(S);
			while(!Q.empty())
			{
				int p=Q.front();Q.pop();
				for(int i=begin[p],q;i;i=next[i])
					if(w[i] && check_max(dis[p]+c[i],dis[q=to[i]]))
						pre[q]=i,Q.push(q);
			}
			return dis[T]!=-INF;
		}
		int solve()
		{
			int ret=0;
			while(bfs())
			{
				ret+=dis[T];
				for(int p=T;p!=S;p=to[pre[p]^1])
					w[pre[p]]--,w[pre[p]^1]++;
			}
			for(int i=begin[S];i;i=next[i])
				if(w[i])return -1;
			for(int i=begin[T];i;i=next[i])
				if(w[i^1])return -1;
			return ret;
		}
	}d;

	int n;

	struct Tree
	{
		int begin[N],next[N*2],to[N*2];
		int limit[N];

		int root,e;

		void add(int x,int y,bool k=1)
		{
			to[++e]=y;
			next[e]=begin[x];
			begin[x]=e;
			if(k)add(y,x,0);
		}
		int dfs(int p,int h,int id,int conf)
		{
			if(limit[p])return limit[p];
			
			if(conf)d.add(p+n,id,1,0);
			else d.add(id,p,1,0);

			int ret=0;
			for(int i=begin[p];i;i=next[i])
				if(to[i]!=h)ret+=dfs(to[i],p,id,conf);
			return ret;
		}
		void Dfs(int p,int h,int conf)
		{
			for(int i=begin[p];i;i=next[i])
				if(to[i]!=h)Dfs(to[i],p,conf);

			if(limit[p])
			{
				int id=++totpoints,flows=limit[p];

				for(int i=begin[p];i;i=next[i])
					if(to[i]!=h)flows-=dfs(to[i],p,id,conf);

				if(conf)d.add(id,T,flows,0),d.add(p+n,id,1,0);
				else d.add(S,id,flows,0),d.add(id,p,1,0);
			}
		}
		void build(bool conf=0){Dfs(root,0,conf);}
	}T0,T1;

	void initialize()
	{
		read(&n,&T0.root,&T1.root);
		for(int i=1,x;i<=n;i++)
			read(&x),d.add(i,i+n,1,x);
		for(int i=1,u,v;i<n;i++)
			read(&u,&v),T0.add(u,v);
		for(int i=1,u,v;i<n;i++)
			read(&u,&v),T1.add(u,v);
		int tmp;
		read(&tmp);
		for(int i=1,k,x;i<=tmp;i++)
			read(&k,&x),T0.limit[k]=x;
		read(&tmp);
		for(int i=1,k,x;i<=tmp;i++)
			read(&k,&x),T1.limit[k]=x;
		totpoints=n*2;
		S=++totpoints,T=++totpoints;
		T0.build(),T1.build(1);
	}
	void solve()
	{
		initialize();
		printf("%d\n",d.solve());
	}
}

int main()
{
	kk::solve();
	return 0;
}