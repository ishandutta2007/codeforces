#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int inf = 1e9;

const int N = 200000 + 10;

int T;
int u[N], v[N];
vector<int> g[N];

int mn[N<<2];
void build(int l,int r,int rt,vector<int>&v) {
	if(l==r) {
		mn[rt] = v[l]; return;
	}
	int mid=(l+r)>>1;
	build(l,mid,rt<<1,v);
	build(mid+1,r,rt<<1|1,v);
	mn[rt]=min(mn[rt<<1],mn[rt<<1|1]);
}
void update(int l,int r,int rt,int pos,int x){
	if(l==r){
		mn[rt]=x; return;
	}
	int mid=(l+r)>>1;
	if(pos<=mid)update(l,mid,rt<<1,pos,x);
	else update(mid+1,r,rt<<1|1,pos,x);
	mn[rt]=min(mn[rt<<1],mn[rt<<1|1]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//cin >> T;
	//while (T --) {
		int n1,n2,n3,n4;
		cin >> n1 >> n2 >> n3 >> n4;
		vector<int> a(n1),b(n2),c(n3),d(n4);
		for (int i=0;i<n1;i++) cin >> a[i];
		for (int i=0;i<n2;i++) cin >> b[i];
		for (int i=0;i<n3;i++) cin >> c[i];
		for (int i=0;i<n4;i++) cin >> d[i];

		int mx = max({n1,n2,n3,n4});
		{
			int m; cin >> m;
			for (int i = 0; i <= mx; i ++) g[i].clear();
			for (int i = 0; i < m; i ++) {
				cin >> u[i] >> v[i];
				g[v[i]-1].push_back(u[i]-1);
			}
			
			build(0,n1-1,1,a);
			for (int i = 0; i < n2; i ++) {
				for (auto j: g[i]) update(0,n1-1,1,j,inf);
				b[i]+=mn[1]; b[i]=min(b[i],inf);
				for (auto j: g[i]) update(0,n1-1,1,j,a[j]);
			}
		}

		//for(auto x: b) printf("# %d\n", x);

		{
			int m; cin >> m;
			for (int i = 0; i <= mx; i ++) g[i].clear();
			for (int i = 0; i < m; i ++) {
				cin >> u[i] >> v[i];
				g[v[i]-1].push_back(u[i]-1);
			}
			
			build(0,n2-1,1,b);
			for (int i = 0; i < n3; i ++) {
				for (auto j: g[i]) update(0,n2-1,1,j,inf);
				c[i]+=mn[1]; c[i]=min(c[i],inf);
				for (auto j: g[i]) update(0,n2-1,1,j,b[j]);
			}
		}

		{
			int m; cin >> m;
			for (int i = 0; i <= mx; i ++) g[i].clear();
			for (int i = 0; i < m; i ++) {
				cin >> u[i] >> v[i];
				g[v[i]-1].push_back(u[i]-1);
			}
			
			build(0,n3-1,1,c);
			for (int i = 0; i < n4; i ++) {
				for (auto j: g[i]) update(0,n3-1,1,j,inf);
				d[i]+=mn[1]; d[i]=min(d[i],inf);
				for (auto j: g[i]) update(0,n3-1,1,j,c[j]);
			}
		}
		int ans = (*min_element(d.begin(),d.end()));
		if (ans == inf) ans = -1;
		cout << ans << endl;
	//}
}