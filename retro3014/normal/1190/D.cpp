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

const int MAX_N = 200000;

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

	struct SEG{
	struct NODE{
		NODE(int l, int r, int sum, int cnt) : l(l), r(r), sum(sum), cnt(cnt) {}
		int l, r;
		int sum, cnt;
	};
	int SZ;
	vector<NODE> seg;
	void Init(int x){
		SZ = x;
		seg.pb({-1, -1, 0, 0});
		init(0, 1, SZ);
	}

	void init(int idx, int s, int e){
		if(s==e)	return;
		seg[idx].l = seg.size(); seg.pb({-1, -1, 0, 0});
		seg[idx].r = seg.size(); seg.pb({-1, -1, 0, 0});
		init(seg[idx].l, s, (s+e)/2);
		init(seg[idx].r, (s+e)/2+1, e);
	}
	void Update(int x, int y){
		update(0, 1, SZ, x, y);
	}
	void update(int idx, int s, int e, int x, int y){
		if(s==e){
			seg[idx].cnt+=y;
			seg[idx].sum = (seg[idx].cnt>0);
			return;
		}
		if(x<=(s+e)/2){
			update(seg[idx].l, s, (s+e)/2, x, y);
		}else{
			update(seg[idx].r, (s+e)/2+1, e, x, y);
		}
		seg[idx].sum = seg[seg[idx].l].sum + seg[seg[idx].r].sum;
	}
	int Sum(int x, int y){
		return sum(0, 1, SZ, x, y);
	}
	int sum(int idx, int s, int e, int x, int y){
		if(x<=s && e<=y)	return seg[idx].sum;
		if(x>e || y<s)	return 0;
		return sum(seg[idx].l, s, (s+e)/2, x, y) + sum(seg[idx].r, (s+e)/2+1, e, x, y);
	}
};

SEG Seg;

int N;
vector<pii> vt;
vector<int> x, y;
map<int, int> mpX, mpY;
vector<int> v[MAX_N+1];

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		x.pb(a); y.pb(b);
		vt.pb({a, b});
	}
	sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());
	sort(y.begin(), y.end()); y.erase(unique(y.begin(), y.end()), y.end());
	for(int i=0; i<x.size(); i++){
		mpX[x[i]] = i+1;
	}
	for(int i=0; i<y.size(); i++){
		mpY[y[i]] = i+1;
	}
	Seg.Init(x.size());
	for(int i=0; i<N; i++){
		vt[i].first = mpX[vt[i].first]; vt[i].second = mpY[vt[i].second];
		Seg.Update(vt[i].first, 1);
		v[vt[i].second].pb(vt[i].first);
	}
	ll ans = 0;
	for(int i=1; i<=y.size(); i++){
		sort(v[i].begin(), v[i].end());
		ll k = Seg.Sum(1, x.size());
		ans += k * (k+1)/2;
		if(!v[i].empty()){
			k = Seg.Sum(1, v[i].front()-1);
			ans -= k * (k+1) / 2;
			k = Seg.Sum(v[i].back() + 1, x.size());
			ans -= k * (k+1) / 2;
		}
		for(int j=0; j<v[i].size()-1; j++){
			k = Seg.Sum(v[i][j]+1, v[i][j+1]-1);
			ans -= k * (k+1) / 2;
		}
		for(int j=0; j<v[i].size(); j++){
			//cout<<v[i][j]<<" ";
			Seg.Update(v[i][j], -1);
		}
		//cout<<endl;
	}

	printf("%lld", ans);
	return 0;
}