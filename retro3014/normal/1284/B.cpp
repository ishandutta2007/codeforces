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
const int MAX_N = 100000;

int N;
vector<int> vt[MAX_N+1];
vector<int> mn, mx;
bool chk[MAX_N+1];

struct SEG{
	struct NODE{
		int l, r;
		int sum;
	};
	int SZ = 1000000;
	vector<NODE> seg;
	void add(){
		seg.pb({-1, -1, 0});
	}
	void Init(){
		add();
		init(0, 0, SZ);
	}
	void init(int idx, int s, int e){
		if(s==e)	return;
		seg[idx].l = seg.size(); add();
		seg[idx].r = seg.size(); add();
		init(seg[idx].l, s, (s+e)/2); init(seg[idx].r, (s+e)/2+1, e);
	}
	void Reset(){
		for(int i=0; i<seg.size(); i++){
			seg[i].sum = 0;
		}
	}
	void Update(int x){
		update(0, 0, SZ, x);
	}
	void update(int idx, int s, int e, int k){
		seg[idx].sum++;
		if(s==e)	return;
		if(k<=(s+e)/2){
			update(seg[idx].l, s, (s+e)/2, k);
		}else{
			update(seg[idx].r, (s+e)/2+1, e, k);
		}
	}
	int Sum(int x, int y){
		return sum(0, 0, SZ, x, y);
	}
	int sum(int idx, int s, int e, int x, int y){
		if(x<=s && e<=y){
			return seg[idx].sum;
		}
		if(x>e  || y<s)	return 0;
		return sum(seg[idx].l, s, (s+e)/2, x, y) + sum(seg[idx].r, (s+e)/2+1, e, x, y);
	}
}Seg;

ll ans = 0;

int main(){
	scanf("%d", &N);
	Seg.Init();
	for(int i=0; i<N; i++){
		int x, y; scanf("%d", &x);
		mn.pb(1000000); mx.pb(0);
		int t = 1000000;
		while(x--){
			scanf("%d", &y);
			vt[i].pb(y);
			if(y>t){
				chk[i] = true;
			}
			t = y;
			mn[i] = min(mn[i], y);
			mx[i] = max(mx[i], y);
		}
		if(mx[i]!=mn[i]){
			ans++;
		}
	}
	//cout<<ans<<endl;
	ll add = 0;
	for(int i=0; i<N; i++){
		ans+=add;
		if(chk[i]){
			ans += (ll)i;
			ans -= add;
			add++;
		}else{
			ans += (ll)Seg.Sum(0, mx[i]-1);
			Seg.Update(mn[i]);
		}
		//cout<<ans<<endl;
	}
	add = 0 ;
	Seg.Reset();
	for(int i=N-1; i>=0; i--){
		ans+=add;
		if(chk[i]){
			ans += (ll)(N-1-i);
			ans -= add;
			add++;
		}else{
			ans += (ll)Seg.Sum(0, mx[i]-1);
			Seg.Update(mn[i]);
		}
		//cout<<ans<<endl;
	}
	cout<<ans;
	return 0;
}