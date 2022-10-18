#include <bits/stdc++.h>
using namespace std;
const int N=1e3+10;
set<pair<int,int>> s,t;
vector<pair<int,int>> now;
vector<int> lk[N];
int a[N];
pair<int,int> b[N];
int n,i,x,y,z,m,ans,tot,lim;
bool ed[N];
int write(int n)
{
	cout<<"? "<<n;
	for (int i=1;i<=n;i++) cout<<' '<<a[i];cout<<endl;
	int x;cin>>x;return x;
}
void bfs()
{
	static int q[N],h,t,u;
	int cnt=0;
	h=1;t=1;q[1]=1;ed[1]=1;
	while (h<=t)
	{
		u=q[h++];
		for (auto v:lk[u]) if (!ed[v])
		{
			ed[v]=1;
			q[++t]=v;
			if (s.find(make_pair(u,v))==s.end())
			{
				s.insert(make_pair(u,v));
				s.insert(make_pair(v,u));
				now.emplace_back(u,v);
				now.emplace_back(v,u);
				++cnt;
				if (cnt==lim) return;
			}
		}
	}
}
int main()
{
	cin>>n;
	for (i=1;i<n;i++) cin>>x>>y,b[i]=make_pair(x,y),lk[x].push_back(y),lk[y].push_back(x),t.insert(b[i]),t.insert(make_pair(y,x));
	for (i=1;i<=n;i++) a[i]=i;m=n;tot=n-1;
	ans=write(m);
	while (tot>1)
	{
		memset(ed,0,sizeof ed);
		lim=(tot>>1);m=0;now.resize(0);
		bfs();
		memset(ed,0,sizeof ed);
		for (auto &[u,v]:now) ed[u]=ed[v]=1;
		for (i=1;i<=n;i++) if (ed[i]) a[++m]=i;
		x=write(m);
		if (x==ans)
		{
			tot>>=1;
			s=t;
			for (auto u:now) s.erase(u);
		}
		else tot-=tot>>1;
	}
	for (i=1;i<n;i++) if (s.find(b[i])==s.end()) {cout<<"! "<<b[i].first<<' '<<b[i].second<<endl;return 0;}
	assert(0);
}
/*
                    ff                                                                                          dsf
                    ff                                                                                          dsf
                    ff                                                                                          dsf
                    ff                                                                                          dsf
                    ff                                                                                          dsf
                    ff                                                                                          dsf
                    ff                                                                                          dsf
                    ff                                                                                          dsf
                    ff                                                                                          dsf
                    ff                                                                                          dsf
                    ff                                                                                          dsf
                    ff                                                                                          dsf
                    ff                                                                                          dsf
                    ff                                                                                          dsf
                    ff                                                                                          dsf
                    ff                                                                                          dsf
                    ff                                                                                          dsf
                    ff                                                                                          dsf
                    ff                                                                                          dsf
*/