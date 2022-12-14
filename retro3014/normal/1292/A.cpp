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

int N, Q;
int state[MAX_N+1];

struct SEG{
	struct NODE{
		int l, r;
		bool tf;
	};
	vector<NODE> seg;
	int SZ;
	void add(){
		seg.pb({-1, -1, true});
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
	void Update(int x){
		update(0, 1, SZ, x);
	}
	void update(int idx, int s, int e, int k){
		if(s==e){
			if(state[s]!=0){
				seg[idx].tf = true;
			}else{
				seg[idx].tf = false;
			}
			return;
		}
		if(k<=(s+e)/2){
			update(seg[idx].l, s, (s+e)/2, k);
		}else{
			update(seg[idx].r, (s+e)/2+1, e, k);
		}
		if(seg[seg[idx].l].tf && seg[seg[idx].r].tf && (state[(s+e)/2] & state[(s+e)/2+1])!=0){
			seg[idx].tf = true;
		}else{
			seg[idx].tf = false;
		}
	}
	bool Chk(){
		return seg[0].tf;
	}
}Seg;

int main(){
	scanf("%d%d", &N, &Q);
	for(int i=1; i<=N; i++){
		state[i] = 3;
	}
	Seg.Init(N);
	for(int i=1; i<=Q; i++){
		int x, y; scanf("%d%d", &x, &y);
		int t = (1<<(x-1));
		state[y] = (state[y] ^ t);
		Seg.Update(y);
		if(Seg.Chk()){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	return 0;
}