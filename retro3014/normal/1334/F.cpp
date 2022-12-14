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
const ll INFLL = 1e15;
const int MAX_N = 500000;



int N, M;
int arr[MAX_N+1];
ll cost[MAX_N+1];
ll Mn[MAX_N+1];
int b[MAX_N+1];
int idx[MAX_N+1];

struct SEG{
	struct NODE{
		int l, r;
		ll mn, lazy;
	};
	vector<NODE> seg;
	int SZ;
	void add(){
		seg.pb({-1, -1, INFLL, 0LL});
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
	void Add(int x, int y, ll z){
		add2(0, 1, SZ, x, y, z);
	}
	void add2(int idx, int s, int e, int x, int y, ll z){
		if(x<=s && e<=y){
			if(seg[idx].mn==INFLL)	return;
			seg[idx].lazy+=z;
			seg[idx].mn+=z;
			return;
		}
		if(x>e || y<s)	return;
		if(seg[idx].lazy!=0){
			if(seg[seg[idx].l].mn!=INFLL){
				seg[seg[idx].l].mn+=seg[idx].lazy; seg[seg[idx].l].lazy+=seg[idx].lazy;
			}
			if(seg[seg[idx].r].mn!=INFLL){
				seg[seg[idx].r].mn+=seg[idx].lazy;	seg[seg[idx].r].lazy+=seg[idx].lazy;
			}
			seg[idx].lazy = 0;
		}
		add2(seg[idx].l, s, (s+e)/2, x, y, z);
		add2(seg[idx].r, (s+e)/2+1, e, x, y, z);
		seg[idx].mn = min(seg[seg[idx].l].mn, seg[seg[idx].r].mn);
	}
	ll Mn(int x){
		return mn(0, 1, SZ, x);
	}
	ll mn(int idx, int s, int e, int k){
		if(s==e)	return seg[idx].mn;
		if(seg[idx].lazy!=0){
			if(seg[seg[idx].l].mn!=INFLL){
				seg[seg[idx].l].mn+=seg[idx].lazy; seg[seg[idx].l].lazy+=seg[idx].lazy;
			}
			if(seg[seg[idx].r].mn!=INFLL){
				seg[seg[idx].r].mn+=seg[idx].lazy;	seg[seg[idx].r].lazy+=seg[idx].lazy;
			}
			seg[idx].lazy = 0;
		}
		if(k<=(s+e)/2){
			return mn(seg[idx].l, s, (s+e)/2, k);
		}else{
			return mn(seg[idx].r, (s+e)/2+1, e, k);
		}
	}
	void Update(int x, ll y){
		update(0, 1, SZ, x, y);
	}
	void update(int idx, int s, int e, int x, ll y){
		if(s==e)	{
			seg[idx].mn = min(seg[idx].mn, y);
			return;
		}
		if(seg[idx].lazy!=0){
			if(seg[seg[idx].l].mn!=INFLL){
				seg[seg[idx].l].mn+=seg[idx].lazy; seg[seg[idx].l].lazy+=seg[idx].lazy;
			}
			if(seg[seg[idx].r].mn!=INFLL){
				seg[seg[idx].r].mn+=seg[idx].lazy;	seg[seg[idx].r].lazy+=seg[idx].lazy;
			}
			seg[idx].lazy = 0;
		}
		if(x<=(s+e)/2){
			update(seg[idx].l, s, (s+e)/2, x, y);
		}else{
			update(seg[idx].r, (s+e)/2+1, e, x, y);
		}
		seg[idx].mn = min(seg[seg[idx].l].mn, seg[seg[idx].r].mn);
	}
}Seg;

ll tree[MAX_N+1];

ll S;

void Add(int x, ll y){
	while(x<=N){
		tree[x]+=y;
		x += (x & -x);
	}
}


ll Sum1(int x){
	ll ret = 0;
	while(x>0){
		ret+=tree[x];
		x-=(x & -x);
	}
	return ret;
}


ll Sum(int x, int y){
	return Sum1(y)-Sum1(x-1);
}

int main(){
	scanf("%d", &N);
	Seg.Init(N);
	for(int i=1; i<=N; i++){
		scanf("%d", &arr[i]);
	}
	for(int i=1; i<=N; i++){
		Mn[i] = INFLL;
		scanf("%lld", &cost[i]);
	}
	scanf("%d", &M);
	for(int i=1; i<=M; i++){
		scanf("%d", &b[i]);
		idx[b[i]] = i;
	}
	bool tf = false;
	for(int i=1; i<=N; i++){
		if(cost[i]<0){
			Seg.Add(arr[i], N, cost[i]);
		}
		if(idx[arr[i]]==0)	{
			Add(arr[i], (ll)cost[i]);
			continue;
		}
		int ind = idx[arr[i]];
		if(ind==1){
			if(ind==M)	tf = true;
			Seg.Update(arr[i], Sum(1, b[ind]));
		}else{
			if(Seg.Mn(b[ind-1])!=INFLL){
				if(ind==M)	tf = true;
				Seg.Update(arr[i], Sum(b[ind-1]+1, b[ind]) + Seg.Mn(b[ind-1]));
			}
			//Mn[arr[i]] = min(Mn[arr[i]], cost[i-1]-cost[i]+Mn[b[ind-1]]);
		}
		/* cout<<arr[i]<<endl;
		for(int j=1; j<=M; j++){
			cout<<Mn[b[j]]<<" ";
		}cout<<endl;*/
		Add(arr[i], (ll)cost[i]);
	}
	if(!tf){
		printf("NO");
		return 0;
	}
	printf("YES\n");
	printf("%lld", Seg.Mn(b[M])+((b[M]!=N)?Sum(b[M]+1, N):0LL));
	return 0;
}