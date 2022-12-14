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

int N;
	struct SEG{
	struct NODE{
		NODE(int l, int r, int lazy) : l(l), r(r), lazy(lazy) {}
		int l, r;
		int lazy;
		// int sum, mn;
	};
	int SZ;
	vector<NODE> seg;
	void Init(int x){
		SZ = x;
		seg.pb({-1, -1, 0});
		init(0, 1, SZ);
	}

	void init(int idx, int s, int e){
		if(s==e)	return;
		seg[idx].l = seg.size(); seg.pb({-1, -1, 0});
		seg[idx].r = seg.size(); seg.pb({-1, -1, 0});
		init(seg[idx].l, s, (s+e)/2);
		init(seg[idx].r, (s+e)/2+1, e);
	}

	void chk(int idx){
		if(seg[idx].lazy==0 || seg[idx].l == -1)	return;
		seg[seg[idx].l].lazy = max(seg[seg[idx].l].lazy, seg[idx].lazy);
		seg[seg[idx].r].lazy = max(seg[seg[idx].r].lazy, seg[idx].lazy);
		seg[idx].lazy = 0;
	}
	void Update(int x, int y){
		update(0, 1, SZ, x, y);
	}
	void update(int idx, int s, int e, int x, int y){
		if(s==e){
			seg[idx].lazy = y;
			return;
		}
		if(seg[idx].lazy>0){
			chk(idx);
		}
		if(x<=(s+e)/2){
			update(seg[idx].l, s, (s+e)/2, x, y);
		}else{
			update(seg[idx].r, (s+e)/2+1, e, x, y);
		}
	}
	void Lazy(int x){
		seg[0].lazy = max(seg[0].lazy, x);
		return;
	}
	int Get(int x){
		return get(0, 1, SZ, x);
	}
	int get(int idx, int s, int e, int k){
		if(s==e){
			return seg[idx].lazy;
		}
		if(seg[idx].lazy>0)	chk(idx);
		if(k<=(s+e)/2){
			return get(seg[idx].l, s, (s+e)/2, k);
		}else{
			return get(seg[idx].r, (s+e)/2+1, e, k);
		}
	}
};

SEG Seg;

int main(){
	scanf("%d", &N);
	Seg.Init(N);
	for(int i=1; i<=N; i++){
		int x; scanf("%d", &x);
		Seg.Update(i, x);
	}
	int Q;
	scanf("%d", &Q);
	for(int i=0; i<Q; i++){
		int t;
		scanf("%d", &t);
		if(t==1){
			int x, y;
			scanf("%d%d", &x, &y);
			Seg.Update(x, y);
		}else{
			int x;
			scanf("%d", &x);
			Seg.Lazy(x);
		}
	}
	for(int i=1; i<=N; i++){
		printf("%d ", Seg.Get(i));
	}
	return 0;
}