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
const int MAX_N = 300000;

int N;

int p[MAX_N+1], q[MAX_N+1];
int idx[MAX_N+1];
struct SEG{
	struct NODE{
		int l, r;
		int mx;
	};
	int SZ;
	vector<NODE> seg;
	void add(){
		seg.pb({-1, -1, 0});
	}
	void Init(int x){
		SZ = x;
		add();
		init(0, 1, SZ);
	}
	void init(int idx, int s, int e){
		if(s==e)	{
			seg[idx].mx = p[s];
			return;
		}
		seg[idx].l = seg.size(); add();
		seg[idx].r = seg.size(); add();
		init(seg[idx].l, s, (s+e)/2); init(seg[idx].r, (s+e)/2+1, e);
		seg[idx].mx = max(seg[seg[idx].l].mx, seg[seg[idx].r].mx);
	}
	void Update(int x){
		update(0, 1, SZ, x);
	}
	void update(int idx, int s, int e, int k){
		if(s==e){
			seg[idx].mx = 0;
			return;
		}
		if(k<=(s+e)/2){
			update(seg[idx].l, s, (s+e)/2, k);
		}else{
			update(seg[idx].r, (s+e)/2+1, e, k);
		}
		seg[idx].mx = max(seg[seg[idx].l].mx, seg[seg[idx].r].mx);
	}
	int Mx(int x, int y){
		return mx(0, 1, SZ, x, y);
	}
	int mx(int idx, int s, int e, int x, int y){
		if(x<=s && e<=y)	return seg[idx].mx;
		if(x>e || y<s)	return 0;
		return max(mx(seg[idx].l, s, (s+e)/2, x, y), mx(seg[idx].r, (s+e)/2+1, e, x, y));
	}
}Seg;

struct SEG2{
	struct NODE{
		int l, r;
		int mx, lazy;
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
		if(s==e)	{
			return;
		}
		seg[idx].l = seg.size(); add();
		seg[idx].r = seg.size(); add();
		init(seg[idx].l, s, (s+e)/2); init(seg[idx].r, (s+e)/2+1, e);
	}
	void Update(int x, int y, int z){
		update(0, 1, SZ, x, y, z);
	}
	void update(int idx, int s, int e, int x, int y, int z){
		if(x<=s && e<=y){
			seg[idx].mx+=z;
			seg[idx].lazy+=z;
			return;
		}
		if(x>e || y<s)	return;
		if(seg[idx].lazy!=0){
			seg[seg[idx].l].mx+=seg[idx].lazy;
			seg[seg[idx].r].mx+=seg[idx].lazy;
			seg[seg[idx].l].lazy+=seg[idx].lazy;
			seg[seg[idx].r].lazy+=seg[idx].lazy;
			seg[idx].lazy = 0;
		}
		update(seg[idx].l, s, (s+e)/2, x, y, z);
		update(seg[idx].r, (s+e)/2+1, e, x, y, z);
		seg[idx].mx = max(seg[seg[idx].l].mx, seg[seg[idx].r].mx);
	}
	int Calc(){
		return calc(0, 1, SZ);
	}
	int calc(int idx, int s, int e){
		if(s==e)	return s;
		if(seg[idx].lazy!=0){
			seg[seg[idx].l].mx+=seg[idx].lazy;
			seg[seg[idx].r].mx+=seg[idx].lazy;
			seg[seg[idx].l].lazy+=seg[idx].lazy;
			seg[seg[idx].r].lazy+=seg[idx].lazy;
			seg[idx].lazy = 0;
		}
		if(seg[seg[idx].l].mx==1){
			return calc(seg[idx].l, s, (s+e)/2);
		}else{
			return calc(seg[idx].r, (s+e)/2+1, e);
		}
	}
}Seg2;



int main(){
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		scanf("%d", &p[i]);
		idx[p[i]] = i;
	}
	Seg.Init(N);
	Seg2.Init(N);
	for(int i=1; i<=N; i++){
		scanf("%d", &q[i]);
		printf("%d ", Seg.Mx(1, N));
		Seg2.Update(q[i], N, 1);
		int n = Seg2.Calc();
		//cout<<n<<" ";
		n  = Seg.Mx(1, n);
		//cout<<n<<endl;
		//cout<<idx[n]<<endl;
		Seg2.Update(idx[n], N, -1);
		Seg.Update(idx[n]);
	}
	return 0;
}