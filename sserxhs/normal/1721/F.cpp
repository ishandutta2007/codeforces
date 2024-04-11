//114514min
//ACM 
#include "bits/stdc++.h"
using namespace std;
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
template<typename typC> bool cmin(typC &x,const typC &y) { if (x>y) { x=y; return 1; } return 0; }
template<typename typC> bool cmax(typC &x,const typC &y) { if (x<y) { x=y; return 1; } return 0; }
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
// void inc(ui &x,const ui &y) { if ((x+=y)>=p) x-=p; }
// void dec(ui &x,const ui &y) { if ((x+=p-y)>=p) x-=p; }
namespace net
{
	const int N=4e5+50;//number of points
	namespace flow
	{
		typedef ll wT;//single flow
		typedef ll cT;//total flow
		const cT inf=numeric_limits<cT>::max();//maximum
		struct Q
		{
			int v;
			wT w;
			int id;
		};
		vector<Q> e[N];
		int fc[N],q[N];
		int n,s,t;
		int bfs()
		{
			fill_n(fc,n,0);
			int p1=0,p2=0,u;
			fc[s]=1; q[0]=s;
			while (p1<=p2)
			{
				int u=q[p1++];
				for (auto [v,w,id]:e[u]) if (w&&!fc[v]) fc[q[++p2]=v]=fc[u]+1;
			}
			return fc[t];
		}
		cT dfs(int u,cT maxf)
		{
			if (u==t) return maxf;
			cT j=0,k;
			for (auto &[v,w,id]:e[u]) if (w&&fc[v]==fc[u]+1&&(k=dfs(v,min(maxf-j,(cT)w))))
			{
				j+=k;
				w-=k;
				e[v][id].w+=k;
				if (j==maxf) return j;
			}
			fc[u]=0;
			return j;
		}
		cT max_flow(const vector<tuple<int,int,wT>> &edges,int S,int T)//[0,n]
		{
			s=S; t=T; n=max(s,t);
			for (auto [u,v,w]:edges) n=max({n,u,v});
			++n;
			assert(n<N);
			for (int i=0; i<n; i++) e[i].clear();
			for (auto [u,v,w]:edges) if (u!=v)
			{
				e[u].push_back({v,w,(int)e[v].size()});
				e[v].push_back({u,0,(int)e[u].size()-1});
			}
			cT r=0;
			while (bfs()) r+=dfs(s,inf);
			return r;
		}
	}
	using flow::max_flow,flow::fc;
	namespace match
	{
		int lk[N];
		int max_match(int n,int m,const vector<pair<int,int>> &edges)//lk[[0,n]]->[0,m]
		{
			++n; ++m;
			assert(max(n,m)<N);
			int s=n+m,t=n+m+1,i;
			vector<tuple<int,int,ll>> eg;
			eg.reserve(n+m+edges.size());
			for (i=0; i<n; i++) eg.push_back({s,i,1});
			for (i=0; i<m; i++) eg.push_back({i+n,t,1});
			for (auto [u,v]:edges) eg.push_back({u,v+n,1});
			int r=max_flow(eg,s,t);
			fill_n(lk,n,-1);
			for (i=0; i<n; i++) for (auto [v,w,id]:flow::e[i]) if (v<s&&!w) { lk[i]=v-n; break; }
			return r;
		}
		bool ed[N];
		int kl[N];
		vector<int> e[N];
		void dfs(int u)
		{
			for (int v:e[u]) if (!ed[v]) ed[v]=1,dfs(kl[v]);
		}
		pair<vector<int>,vector<int>> min_cover(int n,int m,const vector<pair<int,int>> &edges)//[0,n]-[0,m]
		{
			max_match(n,m,edges);
			++n; ++m;
			fill_n(kl,m,-1); fill_n(ed,m,0);
			int i;
			for (i=0; i<n; i++)
			{
				e[i].clear();
				if (lk[i]!=-1) kl[lk[i]]=i;
			}
			for (auto [u,v]:edges) e[u].push_back(v);
			for (i=0; i<n; i++) if (lk[i]==-1) dfs(i);
			vector<int> r[2];
			for (i=0; i<m; i++) if (kl[i]!=-1)
			{
				if (ed[i]) r[1].push_back(i); else r[0].push_back(kl[i]);
			}
			sort(all(r[0]));
			return {r[0],r[1]};
		}
	}
	using match::max_match,match::min_cover,match::lk,match::kl;
	namespace cost_flow
	{
		typedef ll wT;
		typedef ll cT;
		const cT inf=numeric_limits<cT>::max();
		struct Q
		{
			int v;
			wT w;
			cT c;
			int id;
		};
		vector<Q> e[N];
		cT dis[N];
		int pre[N],pid[N],ipd[N];
		bool ed[N];
		int n,s,t;
		pair<wT,cT> spfa()
		{
			queue<int> q;
			fill_n(dis,n,inf);
			memset(ed,0,n*sizeof ed[0]);
			q.push(s); dis[s]=0;
			while (q.size())
			{
				int u=q.front(); q.pop(); ed[u]=0;
				for (auto [v,w,c,id]:e[u]) if (w&&dis[v]>dis[u]+c)
				{
					dis[v]=dis[u]+c;
					pre[v]=u;
					pid[v]=e[v][id].id;
					ipd[v]=id;
					if (!ed[v]) q.push(v),ed[v]=1;
				}
			}
			if (dis[t]==inf) return {0,0};
			wT mw=numeric_limits<wT>::max();
			for (int i=t; i!=s; i=pre[i]) mw=min(mw,e[pre[i]][pid[i]].w);
			for (int i=t; i!=s; i=pre[i]) e[pre[i]][pid[i]].w-=mw,e[i][ipd[i]].w+=mw;
			return {mw,(cT)mw*dis[t]};
		}
		pair<wT,cT> mcmf_spfa(const vector<tuple<int,int,wT,cT>> &edges,int S,int T)//[0,n]
		{
			s=S; t=T; n=max(s,t);
			for (auto [u,v,w,c]:edges) n=max({n,u,v});
			++n;
			assert(n<N);
			for (int i=0; i<n; i++) e[i].clear();
			for (auto [u,v,w,c]:edges) if (u!=v)
			{
				e[u].push_back({v,w,c,(int)e[v].size()});
				e[v].push_back({u,0,-c,(int)e[u].size()-1});
			}
			pair<wT,cT> r{0,0},rr;
			while ((rr=spfa()).first) r={r.first+rr.first,r.second+rr.second};
			return r;
		}
		pair<wT,cT> mcmf_dijk(const vector<tuple<int,int,wT,cT>> &edges,int S,int T)//[0,n]
		{
			s=S; t=T; n=max(s,t);
			for (auto [u,v,w,c]:edges) n=max({n,u,v});
			++n;
			assert(n<N);
			for (int i=0; i<n; i++) e[i].clear();
			for (auto [u,v,w,c]:edges) if (u!=v)
			{
				e[u].push_back({v,w,c,(int)e[v].size()});
				e[v].push_back({u,0,-c,(int)e[u].size()-1});
			}
			static cT h[N];
			auto get_h=[&]()
			{
				fill_n(h,n,inf);
				memset(ed,0,n*sizeof ed[0]);
				queue<int> q;
				q.push(s); h[s]=0;
				while (q.size())
				{
					int u=q.front(); q.pop(); ed[u]=0;
					for (auto [v,w,c,id]:e[u]) if (w&&h[v]>h[u]+c)
					{
						h[v]=h[u]+c;
						if (!ed[v]) q.push(v),ed[v]=1;
					}
				}
				return;
			};
			auto dijkstra=[&]() -> pair<wT,cT>
			{
				static int fl[N],zl[N];
				int i;
				memset(ed,0,n*sizeof ed[0]);
				fill_n(dis,n,inf);
				typedef pair<cT,int> pa;
				priority_queue<pa,vector<pa>,greater<pa>> q;
				dis[s]=0; q.push({0,s});
				while (q.size())
				{
					int u=q.top().second;
					q.pop(); ed[u]=1;
					i=0;
					for (auto [v,w,c,id]:e[u])
					{
						if (w&&dis[v]>dis[u]+c) fl[v]=id,zl[v]=i,q.push({dis[v]=dis[pre[v]=u]+c,v});
						++i;
					}
					while (q.size()&&ed[q.top().second]) q.pop();
				}
				if (dis[t]==inf) return {0,0};
				wT tf=numeric_limits<wT>::max();
				for (i=t; i!=s; i=pre[i]) tf=min(tf,e[pre[i]][zl[i]].w);
				for (i=t; i!=s; i=pre[i]) e[pre[i]][zl[i]].w-=tf,e[i][fl[i]].w+=tf;
				for (int u=0; u<n; u++) for (auto &[v,w,c,id]:e[u]) c+=dis[u]-dis[v];
				return {tf,tf*(h[t]+=dis[t])};
			};
			get_h();
			for (int u=0; u<n; u++) for (auto &[v,w,c,id]:e[u]) c+=h[u]-h[v];
			pair<wT,cT> r{0,0},rr;
			while ((rr=dijkstra()).first) r={r.first+rr.first,r.second+rr.second};
			return r;
		}
	}
	using cost_flow::mcmf_spfa,cost_flow::mcmf_dijk;
	namespace bounded_flow
	{
		typedef ll wT;//single flow
		typedef ll cT;//total flow
		bool valid_flow(const vector<tuple<int,int,wT,wT>> &edges)// l
		{
			if (!edges.size()) return 1;
			int n=0,i;
			cT tot=0;
			for (auto [u,v,l,r]:edges)
			{
				n=max({n,u,v});
				if (l>r) return 0;
			}
			++n;
			static cT cd[N];
			memset(cd,0,n*sizeof cd[0]);
			for (auto [u,v,l,r]:edges) cd[u]+=l,cd[v]-=l;
			vector<tuple<int,int,wT>> eg;
			eg.reserve(n+edges.size());
			for (i=0; i<n; i++) if (cd[i]>0) eg.push_back({i,n+1,cd[i]}),tot+=cd[i];
			else if (cd[i]<0) eg.push_back({n,i,-cd[i]});
			for (auto [u,v,l,r]:edges) eg.push_back({u,v,r-l});
			return tot==flow::max_flow(eg,n,n+1);
		}
		cT valid_flow_st(vector<tuple<int,int,wT,wT>> edges,int s,int t)//-1 invalid, wT=cT
		{
			int n=max(s,t);
			cT tot=0;
			for (auto [u,v,l,r]:edges) n=max({n,u,v}),tot+=(u==s)*r;
			++n;
			edges.push_back({t,s,0,tot});
			if (!valid_flow(edges)) return -1;
			assert(flow::e[s].back().v==t);
			assert(flow::e[t].back().v==s);
			return tot-flow::e[t].back().w;
		}
		cT valid_max_flow(const vector<tuple<int,int,wT,wT>> &edges,int s,int t)//-1 invalid, wT=cT
		{
			cT r=valid_flow_st(edges,s,t);
			if (r<0) return r;
			flow::s=s; flow::t=t;
			flow::e[s].pop_back(); flow::e[t].pop_back();
			while (flow::bfs()) r+=flow::dfs(s,flow::inf);
			return r;
		}
		cT valid_minflow(const vector<tuple<int,int,wT,wT>> &edges,int s,int t)//-1 invalid, wT=cT
		{
			cT r=valid_flow_st(edges,s,t);
			if (r<0) return r;
			flow::s=t; flow::t=s;
			flow::e[s].pop_back(); flow::e[t].pop_back();
			while (flow::bfs()) r-=flow::dfs(t,flow::inf);
			return r;
		}//not check
	}
	using bounded_flow::valid_flow,bounded_flow::valid_flow_st,bounded_flow::valid_max_flow,bounded_flow::valid_minflow;
	namespace bounded_cost_flow
	{
		pair<ll,ll> valid_mcf(const vector<tuple<int,int,ll,ll,ll>> &edges,int s,int t)//[u,v,l,r,c],mincost flow
		{
			int n=max(s,t);
			for (auto [u,v,l,r,c]:edges) n=max({n,u,v});
			++n;
			int ss=n,tt=n+1;
			static ll cd[N];
			memset(cd,0,n*sizeof cd[0]);
			for (auto [u,v,l,r,c]:edges) cd[u]+=l,cd[v]-=l;
			vector<tuple<int,int,ll,ll>> e;
			ll t1=0,t2=0;
			for (int i=0; i<n; i++) if (cd[i]>0) e.push_back({i,tt,cd[i],0}),t2+=cd[i];
			else if (cd[i]<0) e.push_back({ss,i,-cd[i],0});
			for (auto [u,v,l,r,c]:edges) e.push_back({u,v,r-l,c});
			for (auto [u,v,w,c]:e) t1+=(u==s)*w;
			e.push_back({t,s,t1,0});
			auto res=mcmf_spfa(e,ss,tt);//checked dijk
			if (res.first!=t2) return {-1,-1};
			res.first=cost_flow::e[s].back().w;
			for (auto [u,v,l,r,c]:edges) res.second+=l*c;
			return res;
		}
		pair<ll,ll> valid_mcmf(const vector<tuple<int,int,ll,ll,ll>> &edges,int s,int t)//[u,v,l,r,c],mincost max_flow
		{
			auto r=valid_mcf(edges,s,t);
			if (r.first<0) return {-1,-1};
			cost_flow::e[s].pop_back();
			cost_flow::e[t].pop_back();
			cost_flow::s=s; cost_flow::t=t;
			pair<ll,ll> rr;
			while ((rr=cost_flow::spfa()).first) r={r.first+rr.first,r.second+rr.second};//spfa ver. not checked dijk
			return r;
		}
	}
	using bounded_cost_flow::valid_mcf,bounded_cost_flow::valid_mcmf;
	namespace ne_cost_flow
	{
		pair<ll,ll> ne_mcmf(const vector<tuple<int,int,ll,ll>> &edges,int s,int t)
		{
			vector<tuple<int,int,ll,ll,ll>> e;
			for (auto [u,v,w,c]:edges) if (c>=0) e.push_back({u,v,0,w,c}); else
			{
				e.push_back({u,v,w,w,c});
				e.push_back({v,u,0,w,-c});
			}
			return valid_mcmf(e,s,t);
		}
	}
	using ne_cost_flow::ne_mcmf;
}
const int N=2e5+5;
vector<int> e1[N],e2[N];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int n,m,q,i;
	cin>>n>>m>>i>>q;
	vector<pair<int,int>> eg(i);
	i=0;
	map<pair<int,int>,int> mp;
	for (auto &[u,v]:eg)
	{
		cin>>u>>v;
		e1[u].push_back(v);
		e2[v].push_back(u);
		mp[{u,v}]=++i;
	}
	auto [r1,r2]=net::min_cover(n,m,eg);
	vector<int> res;
	for (int u:r2) res.push_back(mp[{net::kl[u],u}]);
	for (int u:r1) res.push_back(mp[{u,net::lk[u]}]);
	ll tot=accumulate(all(res),0ll);
	while (q--)
	{
		int op;
		cin>>op;
		if (op==1)
		{
			cout<<"1\n";
			tot-=res.back(); res.pop_back();
			int u;
			if (r1.size())
			{
				u=r1.back(); r1.pop_back();
				cout<<u<<'\n'<<tot<<endl;
			}
			else
			{
				u=r2.back(); r2.pop_back();
				cout<<-u<<'\n'<<tot<<endl;
			}
		}
		else cout<<res.size()<<'\n'<<res<<endl;
	}
}