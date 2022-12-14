#include <bits/stdc++.h>

#define all(v) (v).begin(), (v).end()
#define sortv(v) sort(all(v))
#define uniqv(v) (v).erase(unique(all(v)), (v).end())
#define pb push_back
#define FI first
#define SE second
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define test 1
#define TEST if(test)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int MOD = 1000000007; // 998244353
const int INF = 2e9;
const ll INFLL = 1e18;
const int MAX_N = 1;

int N, M, P;
vector<pll> A, B;
struct S{
	ll x, y, z;
	bool operator <(const S &a)const{
		return x<a.x;
	}
};
vector<S> v;

struct SEG{
	struct NODE{
		int l, r;
		ll mx, lazy;
	};
	int SZ;
	vector<NODE> seg;
	void add(){
		seg.pb({-1, -1, 0, 0});
	}
	void Init(int x){
		add();
		SZ = x;
		init(0, 1, SZ);
	}
	void init(int idx, int s, int e){
		if(s==e){
			seg[idx].mx = -B[s-1].second;
			return;
		}
		seg[idx].l = seg.size(); add();
		seg[idx].r = seg.size(); add();
		init(seg[idx].l, s, (s+e)/2); init(seg[idx].r, (s+e)/2+1, e);
		seg[idx].mx = max(seg[seg[idx].l].mx, seg[seg[idx].r].mx);
	}
	void Add(int x, int y, ll z){
		add(0, 1, SZ, x, y, z);
	}
	void add(int idx, int s, int e, int x, int y, ll z){
		if(x>e || y<s)	return;
		if(x<=s && e<=y){
			seg[idx].mx+=z;
			seg[idx].lazy+=z;
			return;
		}
		if(seg[idx].lazy!=0){
			seg[seg[idx].l].lazy+=seg[idx].lazy; seg[seg[idx].l].mx+=seg[idx].lazy;
			seg[seg[idx].r].lazy+=seg[idx].lazy; seg[seg[idx].r].mx+=seg[idx].lazy;
			seg[idx].lazy = 0;
		}
		add(seg[idx].l, s, (s+e)/2, x, y, z); add(seg[idx].r ,(s+e)/2+1, e, x, y, z);
		seg[idx].mx = max(seg[seg[idx].l].mx, seg[seg[idx].r].mx);
	}
	ll Mx(){
		return seg[0].mx;
	}
}Seg;

int main(){
	scanf("%d%d%d", &N, &M, &P);
	for(int i=1; i<=N; i++){
		ll a, b; scanf("%lld%lld", &a, &b);
		A.pb({a, b});
	}
	for(int i=1; i<=M; i++){
		ll a, b; scanf("%lld%lld", &a, &b);
		B.pb({a, b});
	}
	for(int i=1; i<=P; i++){
		ll a, b, c; scanf("%lld%lld%lld", &a, &b, &c);
		v.pb({a, b, c});
	}
	sort(A.begin(), A.end()); sort(B.begin(), B.end());
	sort(v.begin(), v.end());
	Seg.Init(M);
	ll ans = -INFLL;
	int idx = 0;
	for(int i=0; i<A.size(); i++){
		ll n = -A[i].second;
		while(idx<v.size() && v[idx].x<A[i].first){
			if(B.back().first>v[idx].y){
				int s = 0, e = M-1, m;
				while(s<e){
					m = (s+e)/2;
					if(B[m].first>v[idx].y){
						e = m;
					}else{
						s = m+1;
					}
				}
				Seg.Add(s+1, M, v[idx].z);
			}
			idx++;
		}
		n+=Seg.Mx();
		ans = max(ans, n);
	}
	printf("%lld", ans);
	return 0;
}