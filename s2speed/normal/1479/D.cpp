#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cerr<<"--------------------------------------"<<endl
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 3e5 + 16 , md = 998244353 , inf = 2e12;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n; res %= md;
		}
		n *= n; n %= md;
		k >>= 1;
	}
	return res;
}

struct fentree {

	int sz;
	vector<int> val;

	void init(int n){
		sz = n;
		val.assign(sz , 0);
		return;
	}

	void add(int i , int k){
		int h = i;
		while(h < sz){
			val[h] += k;
			val[h] %= md; if(val[h] < 0) val[h] += md;
			h |= (h + 1);
		}
		return;
	}

	int cal(int i){
		ll h = i , res = 0;
		while(~h){
			res += val[h];
			h &= (h + 1); h--;
		}
		return res % md;
	}

	void reset(){
		fill(val.begin() , val.end() , 0);
		return;
	}

};

int tv[maxn];
fentree st;
vector<int> adj[maxn];
int bt[maxn] , ft[maxn] , tme = 0 , dis[maxn] , dep = 0 , jad[maxn][20];
int a[maxn] , cv[maxn] , cu[maxn] , dv[maxn] , du[maxn] , cvr[maxn] , cur[maxn] , dvr[maxn] , dur[maxn] , vq[maxn] , uq[maxn] , cq[maxn] , lq[maxn] , rq[maxn] , ans[maxn] , l[maxn] , r[maxn];
vector<int> vc[maxn] , vd[maxn] , mq[maxn];
vector<int> v[maxn];
bitset<maxn> mark , done;

void DFS(int r , int par){
	dis[r] = dep++;
	bt[r] = tme++;
	jad[r][0] = par;
	for(int j = 1 ; j < 20 ; j++){
		if(jad[r][j - 1] == -1) break;
		jad[r][j] = jad[jad[r][j - 1]][j - 1];
	}
	for(auto i : adj[r]){
		if(i == par) continue;
		DFS(i , r);
	}
	ft[r] = tme;
	dep--;
	return;
}

int find_jad(int v , int d){
	d = dis[v] - d;
	for(int j = 0 ; j < 20 ; j++){
		if((1 << j) & d){
			v = jad[v][j];
		}
	}
	return v;
}

int lca(int v , int u){
	if(dis[v] > dis[u]) swap(v , u);
	u = find_jad(u , dis[v]);
	if(v == u) return v;
	for(int j = 19 ; j >= 0 ; j--){
		if(jad[v][j] != jad[u][j]){
			v = jad[v][j];
			u = jad[u][j];
		}
	}
	return jad[v][0];
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	tv[0] = 1;
	for(int i = 1 ; i < maxn ; i++){
		tv[i] = (tv[i - 1] << 1); if(tv[i] > md) tv[i] -= md;
	}
	memset(jad , -1 , sizeof(jad));
	int n , q;
	cin>>n>>q;
	st.init(n);
	for(int i = 0 ; i < n ; i++){
		cin>>a[i]; a[i]--;
	}
	for(int i = 1 ; i < n ; i++){
		int v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	DFS(0 , -1);
	for(int i = 0 ; i < q ; i++){
		cin>>vq[i]>>uq[i]>>lq[i]>>rq[i]; vq[i]--; uq[i]--; lq[i]--; rq[i]--;
		cq[i] = lca(vq[i] , uq[i]);
		vc[lq[i]].push_back(i); vd[rq[i]].push_back(i);
	}
	for(int i = 0 ; i < n ; i++){
		v[a[i]].push_back(bt[i]); v[a[i]].push_back(ft[i]);
	}
	for(int i = 0 ; i < n ; i++){
		sort(all(v[i]));
	}
	for(int i = 0 ; i < n ; i++){
		for(auto j : vc[i]){
			cv[j] = st.cal(bt[vq[j]]);
			cu[j] = st.cal(bt[uq[j]]);
		}
		int h = 0;
		for(auto j : v[i]){
			st.add(j , tv[i] * (1 - (h << 1)));
			h ^= 1;
		}
		for(auto j : vd[i]){
			dv[j] = st.cal(bt[vq[j]]);
			du[j] = st.cal(bt[uq[j]]);
		}
	}
	int cnt = 0;
	for(int i = 0 ; i < q ; i++){
		int h = dv[i] - cv[i] , o = du[i] - cu[i];
		h %= md; o %= md;
		if(h < 0) h += md; if(o < 0) o += md;
		if(h == o){
			cnt++;
			done[i] = true;
			if(a[cq[i]] >= lq[i] && a[cq[i]] <= rq[i]){
				ans[i] = a[cq[i]];
			} else {
				ans[i] = -2;
			}
		}
		l[i] = lq[i] - 1; r[i] = rq[i];
	}
	mark = done;
	while(cnt < q){
//		cout<<cnt<<endl;
//		cout<<l[5]<<' '<<r[5]<<'\n';
		st.reset();
		for(int i = 0 ; i < n ; i++) mq[i].clear();
		for(int i = 0 ; i < q ; i++){
			if(mark[i]) continue;
			if(l[i] == r[i] - 1){
				cnt++;
				mark[i] = true;
				continue;
			}
			int m = (l[i] + r[i]) >> 1;
//			cout<<l[i]<<' '<<r[i]<<' '<<m<<endl;
			mq[m].push_back(i);
		}
		for(int i = 0 ; i < n ; i++){
			int h = 0;
			for(auto j : v[i]){
				st.add(j , tv[i] * (1 - (h << 1)));
				h ^= 1;
			}
			for(auto j : mq[i]){
				int h = st.cal(bt[vq[j]]) - cv[j] , o = st.cal(bt[uq[j]]) - cu[j];
				h %= md; o %= md;
				if(h < 0) h += md; if(o < 0) o += md;
				if(o == h){
					l[j] = i;
				} else {
					r[j] = i;
				}
			}
		}
	}
	for(int i = 0 ; i < n ; i++){
		vc[i].clear(); vd[i].clear();
	}
	for(int i = 0 ; i < q ; i++){
		if(done[i]) continue;
		if(r[i] != a[cq[i]]){
			ans[i] = r[i];
			done[i] = true;
		}
		vc[r[i]].push_back(i);
		vd[r[i] - 1].push_back(i);
	}
	st.reset();
	for(int i = 0 ; i < n ; i++){
		int h = 0;
		for(auto j : v[i]){
			st.add(j , tv[i] * (1 - (h << 1)));
			h ^= 1;
		}
		for(auto j : vd[i]){
			dvr[j] = st.cal(bt[vq[j]]);
			dur[j] = st.cal(bt[uq[j]]);
		}
		for(auto j : vc[i]){
			cvr[j] = st.cal(bt[vq[j]]);
			cur[j] = st.cal(bt[uq[j]]);
		}
	}
	for(int i = 0 ; i < q ; i++){
		if(done[i]) continue;
		int h = dvr[i] - cv[i] , o = dur[i] - cu[i];
		h %= md; o %= md;
		if(h < 0) h += md; if(o < 0) o += md;
		if(h != o){
			dv[i] = dvr[i]; du[i] = dur[i];
			l[i] = lq[i] - 1;
			continue;
		}
		h = dv[i] - cvr[i] , o = du[i] - cur[i];
		h %= md; o %= md;
		if(h < 0) h += md; if(o < 0) o += md;
		if(h != o){
			cv[i] = cvr[i]; cu[i] = cur[i];
			l[i] = r[i]; r[i] = rq[i];
			continue;
		}
		ans[i] = -2;
		done[i] = true;
	}
	mark = done;
	cnt = mark.count();
	while(cnt < q){
		st.reset();
		for(int i = 0 ; i < n ; i++) mq[i].clear();
		for(int i = 0 ; i < q ; i++){
			if(mark[i]) continue;
			if(l[i] == r[i] - 1){
				cnt++;
				mark[i] = true;
				ans[i] = r[i];
				continue;
			}
			int m = (l[i] + r[i]) >> 1;
			mq[m].push_back(i);
		}
		for(int i = 0 ; i < n ; i++){
			int h = 0;
			for(auto j : v[i]){
				st.add(j , tv[i] * (1 - (h << 1)));
				h ^= 1;
			}
			for(auto j : mq[i]){
				int h = st.cal(bt[vq[j]]) - cv[j] , o = st.cal(bt[uq[j]]) - cu[j];
				h %= md; o %= md;
				if(h < 0) h += md; if(o < 0) o += md;
				if(o == h){
					l[j] = i;
				} else {
					r[j] = i;
				}
			}
		}
	}
	for(int i = 0 ; i < q ; i++){
		cout<<ans[i] + 1<<'\n';
	}
	return 0;
}

/*
3 1
2 1 2
1 2 1 3
2 3 1 2
*/