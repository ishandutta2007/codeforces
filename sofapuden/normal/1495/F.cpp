#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 2e5+5;

ll p[mxN],st[mxN],nx,pa[mxN][21],dep[mxN],a[mxN],b[mxN],va[mxN],di[mxN],vis[mxN],cnt[mxN],sum;
set<ll> S;

ll lca(int x, int y){
	if(dep[x] < dep[y])swap(x,y);
	for(int i = dep[x]-dep[y], cn = 0; i; i>>=1, ++cn){
		if(i&1)x = pa[x][cn];
	}
	if(x == y)return x;
	for(int i = 20; i >= 0; --i){
		if(pa[x][i] != pa[y][i]){
			x = pa[x][i], y = pa[y][i];
		}
	}
	return pa[x][0];
}

ll dist(int x, int y){
	return di[x]+di[y]-2*di[lca(x,y)];
}

void add(int x){
	S.insert(x);
	int l = *prev(S.lower_bound(x));
	int r = *(S.upper_bound(x) == S.end() ? S.begin() : S.upper_bound(x));
	sum+=dist(l,x)+dist(x,r)-dist(l,r);
}
void del(int x){
	int l = *prev(S.lower_bound(x));
	int r = *(S.upper_bound(x) == S.end() ? S.begin() : S.upper_bound(x));
	sum-=dist(l,x)+dist(x,r)-dist(l,r);
	S.erase(x);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, q; cin >> n >> q;
	for(int i = 1; i <= n; ++i){
		cin >> p[i];
		while(nx && p[st[nx]] < p[i])--nx;
		pa[i][0] = st[nx];
		dep[i] = dep[pa[i][0]]+1;
		st[++nx] = i;
		for(int j = 1; (1<< j) <= dep[i]; ++j){
			pa[i][j] = pa[pa[i][j-1]][j-1];
		}
	}
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		va[i]+=a[i];
	}
	for(int i = 1; i <= n; ++i){
		cin >> b[i];
		va[i]-=b[i], va[pa[i][0]]+=b[i];
	}
	for(int i = n; i >= 1; --i){
		di[i]+=va[i];
		di[pa[i][0]]+=min(0ll,di[i]);
		di[i]-=min(0ll,di[i]);
	}
	di[0]+=va[0];
	for(int i = 1; i<= n; ++i){
		di[i]+=di[pa[i][0]];
	}
	cnt[0]=1;
	S.insert(0);
	sum = 0;
	while(q--){
		int x; cin >> x;
		if(vis[x]){
			vis[x] = 0;
			if(!(--cnt[pa[x][0]]))
				del(pa[x][0]);
		}
		else{
			vis[x] = 1;
			if(!(cnt[pa[x][0]]++))
				add(pa[x][0]);
		}
		cout << sum/2+di[0] << '\n';

	}
}