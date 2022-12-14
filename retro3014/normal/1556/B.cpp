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
const int MAX_N = 1000;

int T;
int N;
vector<int> v0, v1;

struct Seg{
	struct Node{
		int l, r;
		int sum;
	};
	vector<Node> seg;
	int SZ;
	void add(){
		seg.pb({-1, -1, 0});
	}
	void init(int idx, int s, int e){
		seg[idx].sum = e-s+1;
		if(s==e)	return;
		seg[idx].l = seg.size(); add();
		seg[idx].r = seg.size(); add();
		init(seg[idx].l, s ,(s+e)/2);
		init(seg[idx].r, (s+e)/2+1, e);
	}
	void Init(int x){
		seg.clear();
		SZ = x;
		add();
		init(0, 1, SZ);
	}
	void update(int idx, int s, int e, int k){
		seg[idx].sum--;
		if(s==e)	return;
		if(k<=(s+e)/2)	update(seg[idx].l, s, (s+e)/2, k);
		else	update(seg[idx].r, (s+e)/2+1, e, k);
	}
	void Update(int x){
		update(0, 1, SZ, x);
	}
	int sum(int idx, int s, int e, int x, int y){
		if(x<=s && e<=y)	return seg[idx].sum;
		if(x>e || y<s)	return 0;
		return sum(seg[idx].l, s, (s+e)/2, x, y) + sum(seg[idx].r, (s+e)/2+1, e, x, y);
	}
	int Sum(int x, int y){
		return sum(0, 1, SZ, x, y);
	}

} Seg;

int main(){
	scanf("%d", &T);
	while(T--){
		v0.clear();
		v1.clear();
		scanf("%d", &N);
		Seg.Init(N);
		for(int i=1; i<=N; i++){
			int x; scanf("%d", &x);
			if(x%2==0)	v0.pb(i);
			else	v1.pb(i);
		}
		int ans = -1;
		if(N%2==0){
			if(v0.size()==v1.size()){
				int m1 = 0, m2 = 0;
				for(int i=0; i*2<N; i++){
					m1+=Seg.Sum(1, v0[i]-1);
					Seg.Update(v0[i]);
					m1+=Seg.Sum(1, v1[i]-1);
					Seg.Update(v1[i]);
				}
				Seg.Init(N);
				for(int i=0; i*2<N; i++){
					m2+=Seg.Sum(1, v1[i]-1);
					Seg.Update(v1[i]);
					m2+=Seg.Sum(1, v0[i]-1);
					Seg.Update(v0[i]);
				}
				ans = min(m1, m2);
			}
		}else{
			if(v0.size()==v1.size()+1){
				int m = 0;
				for(int i=0; i*2<N; i++){
					m+=Seg.Sum(1, v0[i]-1);
					Seg.Update(v0[i]);
					if(i*2==N-1)	break;
					m+=Seg.Sum(1, v1[i]-1);
					Seg.Update(v1[i]);
				}
				ans = m;
			}else if(v0.size()+1 == v1.size()){
				int m = 0;
				for(int i=0; i*2<N; i++){
					m+=Seg.Sum(1, v1[i]-1);
					Seg.Update(v1[i]);
					if(i*2==N-1)	break;
					m+=Seg.Sum(1, v0[i]-1);
					Seg.Update(v0[i]);
				}
				ans = m;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}