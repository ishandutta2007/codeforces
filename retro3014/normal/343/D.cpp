#include <bits/stdc++.h>

#define pb push_back
#define all(v) ((v).begin(), (v).end())
#define sortv(v) sort(all(v))
#define sz(v) ((int)(v).size())
#define uniqv(v) (v).erase(unique(all(v)), (v).end())
#define umax(a, b) (a)=max((a), (b))
#define umin(a, b) (a)=min((a), (b))
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define rep(i,n) FOR(i,1,n)
#define rep0(i,n) FOR(i,0,(int)(n)-1)
#define FI first
#define SE second
#define INF 2000000000
#define INFLL 1000000000000000000LL


using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAX_N = 500000;

struct SEG{
	SEG(int l, int r, int sum, bool tf, bool lazy) : l(l), r(r), sum(sum), tf(tf), lazy(lazy) {}
	int l, r;
	int sum;
	bool tf;
	bool lazy;
};

vector<SEG> seg;

vector<int> gp[MAX_N+1];

int N, Q;

int cnt = 0;
int num[2][MAX_N+1];
int par[MAX_N+1];

void init(int idx, int s, int e){
	if(s==e)	return;
	seg[idx].l = seg.size(); seg.pb({-1, -1, 0, 0, 0});
	seg[idx].r = seg.size(); seg.pb({-1, -1, 0, 0, 0});
	init(seg[idx].l, s, (s+e)/2);
	init(seg[idx].r, (s+e)/2+1, e);
}

void update(int idx, int s, int e, int x, int y){
	if(seg[idx].tf)	return;
	if(x<=s && e<=y){
		seg[idx].tf = true;
		return;
	}
	if(x>e || y<s)	return;
	update(seg[idx].l, s, (s+e)/2, x, y);
	update(seg[idx].r, (s+e)/2+1, e, x, y);
}

void lazy(int idx, int s, int e, int x, int y){
	if(seg[idx].lazy)	return;
	if(x<=s && e<=y){
		seg[idx].lazy = true;
		return;
	}
	if(x>e || y<s)	return;
	lazy(seg[idx].l, s, (s+e)/2, x, y);
	lazy(seg[idx].r, (s+e)/2+1, e, x, y);
}

bool calc(int idx, int s, int e, int k){
	if(seg[idx].tf)	return true;
	if(s==e)	return false;
	if(k<=(s+e)/2){
		return calc(seg[idx].l, s, (s+e)/2, k);
	}
	return calc(seg[idx].r, (s+e)/2+1, e, k);
}

void add(int idx, int s, int e, int k){
	if(seg[idx].lazy){
		seg[idx].sum = 0;
		seg[idx].lazy = false;
		if(seg[idx].l!=-1){
			seg[seg[idx].l].lazy = true;
			seg[seg[idx].r].lazy = true;
		}
	}
	seg[idx].sum++;
	if(s==e)	return;
	if(k<=(s+e)/2){
		add(seg[idx].l, s, (s+e)/2, k);
	}else{
		add(seg[idx].r, (s+e)/2+1, e, k);
	}
}

int sum(int idx, int s, int e, int x, int y){
	if(seg[idx].lazy){
		if(seg[idx].l!=-1){
			seg[seg[idx].l].lazy = true;
			seg[seg[idx].r].lazy = true;
		}
		seg[idx].sum = 0;
		seg[idx].lazy = false;
	}
	if(x<=s && e<=y)	return seg[idx].sum;
	if(x>e || y<s)	return 0;
	return sum(seg[idx].l, s, (s+e)/2, x, y) + sum(seg[idx].r, (s+e)/2+1, e, x, y);
}

bool ans(int x){
	if(!calc(0, 1, N*2, num[0][x]))	return false;
	if(sum(0, 1, N*2, num[0][x], num[1][x])>0)	return false;
	return true;
}

void dfs(int x){
	num[0][x] = ++cnt;
	for(int i=0; i<gp[x].size(); i++){
		if(gp[x][i]==par[x])	continue;
		par[gp[x][i]] = x;
		dfs(gp[x][i]);
	}
	num[1][x] = ++cnt;
}

int main(){
	cin>>N;
	seg.pb({-1, -1, 0, 0, 0});
	init(0, 1, N*2);
	for(int i=0; i<N-1; i++){
		int a, b;
		cin>>a>>b;
		gp[a].pb(b); gp[b].pb(a);
	}
	dfs(1);
	cin>>Q;
	for(int i=0; i<Q; i++){
		int a, b;
		cin>>a>>b;
		if(a==1){
			update(0, 1, N*2, num[0][b], num[1][b]);
			if(sum(0, 1, N*2, num[0][b], num[1][b])>0 && b!=1){
				add(0, 1, N*2, num[0][par[b]]);
			}
			lazy(0, 1, N*2, num[0][b], num[1][b]);
		}else if(a==2){
			if(!calc(0, 1, N*2, num[0][b]))	continue;
			add(0, 1, N*2, num[0][b]);
		}else{
			cout<<ans(b)<<endl;
		}
	}
	return 0;
}