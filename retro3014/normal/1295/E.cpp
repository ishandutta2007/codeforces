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
const int MAX_N = 200000;

int arr[MAX_N+1], idx[MAX_N+1];
ll cost[MAX_N+1];
int N;

struct SEG{
	struct NODE{
		int l, r;
		ll mn, lazy;
	};
	vector<NODE> seg;
	int SZ;
	void add(){
		seg.pb({-1, -1, 0, 0});
	}
	void Init(int x){
		SZ = x;
		add();
		init(0, 1, SZ);
	}
	void init(int idx, int s, int e){
		if(s==e)	return; 
		seg[idx].l = seg.size(); add();
		seg[idx].r = seg.size(); add();
		init(seg[idx].l, s, (s+e)/2);
		init(seg[idx].r, (s+e)/2+1, e);
	}
	void Update(int x, int y, ll z){
		update(0, 1, SZ, x, y, z);
	}
	void update(int idx, int s, int e, int x, int y, ll z){
		if(x<=s && e<=y){
			seg[idx].lazy+=z;
			seg[idx].mn+=z;
			return;
		}
		if(x>e || y<s)	return;
		if(seg[idx].lazy!=0){
			seg[seg[idx].l].lazy+=seg[idx].lazy; seg[seg[idx].r].lazy+=seg[idx].lazy;
			seg[seg[idx].l].mn+=seg[idx].lazy; seg[seg[idx].r].mn+=seg[idx].lazy;
			seg[idx].lazy = 0;
		}
		update(seg[idx].l, s, (s+e)/2, x, y, z);
		update(seg[idx].r, (s+e)/2+1, e, x, y, z);
		seg[idx].mn = min(seg[seg[idx].l].mn, seg[seg[idx].r].mn);
	}
	ll Mn(){
		return seg[0].mn;
	}
}Seg;

int main(){
	scanf("%d", &N);
	Seg.Init(N-1);
	for(int i=1; i<=N; i++){
		scanf("%d", &arr[i]);
		idx[arr[i]] = i;
	}
	for(int i=1; i<=N; i++){
		scanf("%lld", &cost[i]);
		if(i!=N)	Seg.Update(i, N-1, cost[i]);
	}
	ll ans = INFLL;
	ans = min(ans, Seg.Mn());
	//cout<<Seg.Mn()<<endl;
	for(int i=1; i<=N; i++){
		Seg.Update(idx[i], N-1, -cost[idx[i]]);
		Seg.Update(1, idx[i]-1, cost[idx[i]]);
		ans = min(ans, Seg.Mn());
		//cout<<Seg.Mn()<<endl;
	}
	printf("%lld", ans);
	return 0;
}