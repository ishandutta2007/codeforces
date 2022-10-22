#include<bits/stdc++.h>
using namespace std;
using nagai=long long;
#define sz(x) (int)(x.size())

const int N=200200;

nagai c[N];
vector<int>g[N],ch[N];
int tin[N],tout[N];
int tot=0;
void d(int u,int p=-1){
	tin[u]=tot;
	if(u&&g[u].size()==1)tot++;
	for(int v:g[u])
		if(v!=p)
			d(v,u);
	tout[u]=tot;
}

int p[N];

int getp(int x){
	return p[x]==x?x:p[x]=getp(p[x]);
}
void unite(int a,int b){
	p[getp(a)]=getp(b);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;++i)
		cin>>c[i];
	for(int i=0;i<n-1;++i){
		int a,b;
		cin>>a>>b;
		--a,--b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	d(0);
	vector<int>mem(c,c+n);
	sort(mem.begin(),mem.end());
	mem.erase(unique(mem.begin(),mem.end()),mem.end());
	vector<int>ord(n);
	iota(ord.begin(),ord.end(),0);
	iota(p,p+N,0);
	sort(ord.begin(),ord.end(),[&](int a,int b){
			return c[a]<c[b];
			});
	nagai ans=0;
	int cnt=0;
	vector<int>good;
	for(int i=0;i<n;){
		vector<int>cur;
		int j=i;
		for(;i<n&&c[ord[i]]==c[ord[j]];++i)cur.push_back(ord[i]);
		for(int x:cur){
			if(getp(tin[x])!=getp(tout[x]))
				good.push_back(x);
		}
		for(int x:cur){
			if(getp(tin[x])!=getp(tout[x]))
				unite(tin[x],tout[x]),ans+=c[x],cnt++;
		}
	}
	cout<<ans<<' '<<good.size()<<'\n';
	sort(good.begin(),good.end());
	for(auto&x:good)
		cout<<x+1<<' ';
	cout<<'\n';
	return 0;
}