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
const int MAX_N = 300010;

int T;
int N;
vector<ll> v;

ll sum[MAX_N+1];
ll ans;

struct SEG{
	struct NODE{
		int l, r;
		ll mn, lz, idx;
	};
	vector<NODE> seg;
	int SZ;
	void add(){
		seg.pb({-1, -1, INFLL, 0, -1});
	}
	void init(int idx, int s, int e){
		seg[idx].idx = e;
		if(s==e){
			return;
		}
		seg[idx].l = seg.size(); add();
		seg[idx].r = seg.size(); add();
		init(seg[idx].l, s, (s+e)/2);
		init(seg[idx].r, (s+e)/2+1, e);
	}
	void Init(int x){
		seg.clear();
		SZ = x;
		add();
		init(0, 1, SZ);
	}
	void lazy(int idx){
		if(seg[idx].lz!=0){
			if(seg[idx].l!=-1){
				if(seg[seg[idx].l].mn!=INFLL){
					seg[seg[idx].l].mn += seg[idx].lz;
					seg[seg[idx].l].lz += seg[idx].lz;
				}if(seg[seg[idx].r].mn!=INFLL){
					seg[seg[idx].r].mn += seg[idx].lz;
					seg[seg[idx].r].lz += seg[idx].lz;
				}
			}
			seg[idx].lz = 0;
		}
	}
	void update(int idx, int s, int e, int x, ll y){
		lazy(idx);
		if(s==e){
			//cout<<s<<" "<<y<<endl;
			seg[idx].mn = y;
			seg[idx].idx = s;
			return;
		}
		if(x<=(s+e)/2)	update(seg[idx].l, s, (s+e)/2, x, y);
		else update(seg[idx].r, (s+e)/2+1, e, x, y);
		if(seg[seg[idx].l].mn<=seg[seg[idx].r].mn){
			seg[idx].mn = seg[seg[idx].l].mn;
			seg[idx].idx = seg[seg[idx].l].idx;
		}else{
			seg[idx].mn = seg[seg[idx].r].mn;
			seg[idx].idx = seg[seg[idx].r].idx;
		}
	}
	void Update(int x, ll y){
		update(0, 1, SZ, x, y);
	}
	void add2(int idx, int s, int e, int x, int y, ll z){
		lazy(idx);
		if(x<=s && e<=y){
			if(seg[idx].mn!=INFLL){
				seg[idx].mn+=z;
				seg[idx].lz+=z;
			}
			return;
		}
		if(x>e || y<s)	return;
		add2(seg[idx].l, s, (s+e)/2, x, y, z);
		add2(seg[idx].r, (s+e)/2+1, e, x, y, z);
		if(seg[seg[idx].l].mn<=seg[seg[idx].r].mn){
			seg[idx].mn = seg[seg[idx].l].mn;
			seg[idx].idx = seg[seg[idx].l].idx;
		}else{
			seg[idx].mn = seg[seg[idx].r].mn;
			seg[idx].idx = seg[seg[idx].r].idx;
		}
	}
	void Add(int x, int y, ll z){
		add2(0, 1, SZ, x, y, z);
	}
	ll findmn(int idx, int s, int e, int x, int y){
		lazy(idx);
		if(x<=s && e<=y){
			return seg[idx].mn;
		}
		if(x>e || y<s)	return INFLL;
		return min(findmn(seg[idx].l, s, (s+e)/2, x, y), findmn(seg[idx].r, (s+e)/2+1, e, x, y));
	}
	pll findmn2(int idx, int s, int e, int x, int y){
		lazy(idx);
		if(s==e){
			return {seg[idx].mn, s};
		}
		ll p1 = findmn(seg[idx].l, s, (s+e)/2, x, y);
		if(p1<=0){
			return findmn2(seg[idx].l, s, (s+e)/2, x, y);
		}else{
			return findmn2(seg[idx].r, (s+e)/2+1, e, x, y);
		}
	}
	pll Mn(int x, int y){
		return findmn2(0, 1, SZ, x, y);
	}
}Seg1, Seg2;

int main(){
	scanf("%d", &T);
	while(T--){
		ans = 0;
		scanf("%d", &N);
		v.clear();
		for(int i=0 ;i<N; i++){
			ll x;scanf("%lld", &x);
			v.pb(x);
		}
		Seg1.Init(N); Seg2.Init(N);
		for(int i=N; i>=1; i--){
			sum[i] = 0;
			if(v[i-1]==0){
				if(i!=N)	sum[i] = sum[i+1]+1;
				else sum[i] = 1;
				ans+=sum[i];
				if(i%2){
					Seg1.Update(i, v[i-1]);
				}else{
					Seg2.Update(i, v[i-1]);
				}	
			}else{
				if(i%2){
					Seg1.Add(i+1, N, v[i-1]);
					Seg2.Add(i+1, N, -v[i-1]);
				}else{
					Seg1.Add(i+1, N, -v[i-1]);
					Seg2.Add(i+1, N, v[i-1]);
				}
				pll p1 = Seg1.Mn(i+1, N), p2 = Seg2.Mn(i+1, N);
				//cout<<p1.first<<" "<<p1.second<<" "<<p2.first<<" "<<p2.second<<endl;
				int k = N+1;
				if(p1.first==0 && (p1.second<p2.second || p2.first>0)){
					sum[i]++;
					k = p1.second;
				}else if(p2.first==0 && (p2.second<p1.second || p1.first>0)){
					sum[i]++;
					k = p2.second;
				}
				//cout<<i<<" "<<k<<endl;
				if(i%2){
					Seg1.Update(i, v[i-1]);
				}else{
					Seg2.Update(i, v[i-1]);
				}			
				if(k<N){
					sum[i]+=sum[k+1];
				}
				ans+=sum[i];
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}