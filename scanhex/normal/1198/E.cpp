#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
#define sz(x) int((x).size())

const int N=100000;
nagai w[N];
int l,r;
vector<int>g[N];
vector<int>g1[N];
vector<int>g2[N];

#define int long long

struct Edge {
    int to, rev, f, cap;
};

struct max_flow_dinic {
    vector<vector<Edge>> g;
    vector<int> dist, q, work;

    max_flow_dinic(int nodes) : g(nodes), dist(nodes), q(nodes), work(nodes) {}

    void add_bidi_edge(int s, int t, int cap) {
//		cerr<<s<<' '<<t<<'\n';
        Edge a = {t, (int) g[t].size(), 0, cap};
        Edge b = {s, (int) g[s].size(), 0, 0};
        g[s].emplace_back(a);
        g[t].emplace_back(b);
    }

    bool dinic_bfs(int src, int dest) {
        fill(dist.begin(), dist.end(), -1);
        dist[src] = 0;
        int qt = 0;
        q[qt++] = src;
        for (int qh = 0; qh < qt; qh++) {
            int u = q[qh];
            for (auto &e : g[u]) {
                int v = e.to;
                if (dist[v] < 0 && e.f < e.cap) {
                    dist[v] = dist[u] + 1;
                    q[qt++] = v;
                }
            }
        }
        return dist[dest] >= 0;
    }

    int dinic_dfs(int u, int dest, int f) {
        if (u == dest)
            return f;
        for (int &i = work[u]; i < g[u].size(); i++) {
            Edge &e = g[u][i];
            if (e.cap <= e.f) continue;
            int v = e.to;
            if (dist[v] == dist[u] + 1) {
                int df = dinic_dfs(v, dest, min(f, e.cap - e.f));
                if (df > 0) {
                    e.f += df;
                    g[v][e.rev].f -= df;
                    return df;
                }
            }
        }
        return 0;
    }

    int max_flow(int src, int dest) {
        int result = 0;
        while (dinic_bfs(src, dest)) {
            fill(work.begin(), work.end(), 0);
            while (int delta = dinic_dfs(src, dest, numeric_limits<int>::max()))
                result += delta;
        }
        return result;
    }

    vector<bool> min_cut() {
        vector<bool> cut(g.size());
        for (int i = 0; i < cut.size(); ++i) {
            cut[i] = dist[i] != -1;
        }
        return cut;
    }

    void clear_flow() {
        for (auto &v : g)
            for (Edge &e : v)
                e.f = 0;
    }
};

#undef int

int mt[N];
bool used[N];
nagai kuhn(int u){
	if(used[u])return false;
	used[u]=true;
	for(int v:g[u]){
		if((mt[v]==-1)||kuhn(mt[v])){
			mt[v]=u;
			return true;
		}
	}
	return false;
}
void d(int u){
	if(used[u])return;
	used[u]=true;
	for(int v:g2[u])
		d(v);
}
const nagai oo=0x3f3f3f3f;
nagai solve(){
	max_flow_dinic govno(l+r+2);
	int s=l+r;
	int t=l+r+1;
	for(int i=0;i<l;++i)
		for(int j:g[i])
			govno.add_bidi_edge(i,j,oo);
	for(int i=0;i<l;++i)
		govno.add_bidi_edge(s,i,w[i]);
	for(int i=l;i<l+r;++i)
		govno.add_bidi_edge(i,t,w[i]);
	return govno.max_flow(s,t);
	vector<int>ord(l);
	iota(ord.begin(),ord.end(),0);
	sort(ord.begin(),ord.end(),[&](int a,int b){
			return w[a]<w[b];
			});
	nagai ans=0;
	fill(mt,mt+l+r,-1);
	for(int i:ord){
		fill(used,used+l+r,false);
		ans+=kuhn(i)*w[i];
	}
	ord.resize(r);
	iota(ord.begin(),ord.end(),l);
	sort(ord.begin(),ord.end(),[&](int a,int b){
			return w[a]<w[b];
			});
	for(int i:ord){
		fill(used,used+l+r,false);
		ans+=kuhn(i)*w[i];
	}
	vector<bool>good(l+r);
	for(int i=0;i<l+r;++i){
		if(mt[i]!=-1)good[mt[i]]=true;
	}
	for(int i=0;i<l+r;++i){
		for(int j:g[i])
			if(good[j])
				g1[i].push_back(j);
		g[i].swap(g1[i]);
	}
	ans=0;
	fill(mt,mt+l+r,-1);
	ord.resize(l);
	iota(ord.begin(),ord.end(),0);
	vector<bool>kek(l+r);
	for(int i:ord){
		fill(used,used+l+r,false);
		if(kuhn(i))kek[i]=true;
	}
	for(int i=0;i<l;++i){
		for(int j:g1[i])
			if(mt[j]==i)
				g2[j].push_back(i);
			else
				g2[i].push_back(j);
	}
	fill(used,used+l+r,false);
	for(int i=0;i<l;++i){
		if(!kek[i])
			d(i);
	}
	ans=0;
	for(int i=0;i<l+r;++i){
		if((i<l&&!used[i])||(i>=l&&used[i])){
//			cerr<<i<<'\n';
			ans+=w[i];
		}
	}
	/*
	ans=0;
	for(int i=0;i<l+r;++i){
		if((i<l&&!good[i])||(i>=l&&good[i])){
//			cerr<<i<<'\n';
			ans+=w[i];
		}
	}
	*/
	return ans;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	if(m==0){
		cout<<0<<'\n';
		return 0;
	}
	vector<int>xs,ys;
	vector<array<int,4>>kek;
	for(int i=0;i<m;++i){
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		++x2,++y2;
		xs.push_back(x1);
		ys.push_back(y1);
		xs.push_back(x2);
		ys.push_back(y2);
		kek.push_back({x1,y1,x2,y2});
	}
	sort(xs.begin(),xs.end());
	xs.erase(unique(xs.begin(),xs.end()),xs.end());
	sort(ys.begin(),ys.end());
	ys.erase(unique(ys.begin(),ys.end()),ys.end());
	l=xs.size()-1,r=ys.size()-1;
	vector<vector<int>>mem(l,vector<int>(r));
	for(auto&[a,b,c,d]:kek){
		a=lower_bound(xs.begin(),xs.end(),a)-xs.begin();
		b=lower_bound(ys.begin(),ys.end(),b)-ys.begin();
		c=lower_bound(xs.begin(),xs.end(),c)-xs.begin();
		d=lower_bound(ys.begin(),ys.end(),d)-ys.begin();
//		cerr<<a<<' '<<b<<' '<<c<<' '<<d<<'\n';
		for(int i=a;i<c;++i)
			for(int j=b;j<d;++j)
				mem[i][j]=true;
	}
	for(int i=0;i<l;++i)w[i]=xs[i+1]-xs[i];
	for(int i=0;i<r;++i)w[l+i]=ys[i+1]-ys[i];
	for(int i=0;i<l;++i)
		for(int j=0;j<r;++j){
			if(mem[i][j]){
				g[i].push_back(j+l),g[j+l].push_back(i);
			}
		}
//	nagai s=xs.back()-xs.front()+ys.back()-ys.front();
	cout<<solve()<<'\n';
	return 0;
}