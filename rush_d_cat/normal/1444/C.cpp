
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 500000 + 10;
int n,m,k;
int c[N];
 
int par[N],dis[N],sz[N];
int par_copy[N],dis_copy[N],sz_copy[N];
vector<int> g[N];
vector<int> bins[N];
 
int top = 0;
int recorder[10000000 + 10];

int find(int x, bool rec) {
	if(par[x] == x) return x;
	int r = find(par[x], rec);
	return r;
}

int q(int x) {
	if(par[x] == x) return 0;
	return dis[x] ^ q(par[x]);
}

bool unite(int u,int v, bool rec) {
	int fu = find(u, rec);
	int fv = find(v, rec);
	if (fu == fv) {
		if (q(u) == q(v)) return false;
	} 
	if (sz[fu] > sz[fv]) {
		swap(fu, fv);
	}
	sz[fv] += sz[fu];
	par[fu] = fv;
	dis[fu] = 1 ^ q(u) ^ q(v);

	if (rec) {
		recorder[++top] = fu;
		recorder[++top] = fv;
	}
	return true;
}
 
bool valid[N]; int clo[N];
bool cmp(pair<int,int> x,pair<int,int> y) {
	return c[x.first] < c[y.first];
}
void look() {
	for(int i=1;i<=n;i++) {
		find(i,0);
		printf("i=%d,par=%d,dis=%d\n", i,par[i],dis[i]);
	}
}
int main() {
	for(int i=0;i<N;i++){
		par[i]=i; dis[i]=0; sz[i]=1;
	}
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++){
		valid[i]=1;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]); bins[c[i]].push_back(i);
	}	
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
		if(c[u] == c[v]) {
			if (unite(u, v, false) == false) 
				valid[c[u]] = 0;
		}
	}
	for(int i=1;i<=n;i++) {
		par_copy[i] = par[i], dis_copy[i] = dis[i]; sz_copy[i] = sz[i];
	}
 
	LL ans=0;
	int total_Valid = 0;
	for(int i=k;i>=1;i--) {
		if(valid[i]) {
			total_Valid ++;
			LL tmp_add = total_Valid - 1;
			vector< pair<int,int> > tmp;
			for(auto u:bins[i]){
				for(auto v:g[u]){
					if(c[v]>c[u] && valid[c[v]]) tmp.push_back( make_pair(v,u) );
				}
			}
			sort(tmp.begin(),tmp.end(),cmp);
			for(int j=0,k=0;j<tmp.size();j=k) {
				while(k<tmp.size() && c[tmp[j].first]==c[tmp[k].first]) k++;
				top=0; bool ok=true;
				for(int y=j;y<k;y++){
					//printf("join %d %d\n", tmp[y].first,tmp[y].second);
					if(unite(tmp[y].first,tmp[y].second,true)==false) {
						ok=false; //printf("GG\n");
					}					
					//look();
				}

				if(ok==false) tmp_add --;
				//printf("\n");
				for(int y=1;y<=top;y++) {
					int x = recorder[y];
					dis[x] = dis_copy[x];
					par[x] = par_copy[x];
					sz[x] = sz_copy[x];
				}
			}
			//printf("i=%d,add=%lld\n", i,tmp_add);
			ans += tmp_add;
		}
 
	}
	printf("%lld\n", ans);
}