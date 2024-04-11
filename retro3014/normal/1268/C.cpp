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
#define test 0
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


struct SEG{
	struct NODE{
		int l, r;
		ll sum, cnt, lazy;
	};
	vector<NODE> seg;
	int SZ;
	void add(){
		seg.pb({-1, -1, 0, 0, 0});
	}
	void Init(int x){
		SZ = x; add();
		init(0, 1, SZ);
	}
	void init(int idx, int s, int e){
		seg[idx].cnt = (ll)(e-s+1);
		if(s==e)	return;
		seg[idx].l = seg.size(); add();
		seg[idx].r = seg.size(); add();
		init(seg[idx].l, s, (s+e)/2);
		init(seg[idx].r, (s+e)/2+1, e);
	}
	void calc(int idx){
		if(seg[idx].l!=-1 && seg[idx].lazy!=0){
			seg[seg[idx].l].sum += seg[idx].lazy * seg[seg[idx].l].cnt; seg[seg[idx].l].lazy += seg[idx].lazy; 
			seg[seg[idx].r].sum += seg[idx].lazy * seg[seg[idx].r].cnt; seg[seg[idx].r].lazy += seg[idx].lazy;
			seg[idx].lazy = 0;
		}
	}
	void Update(int x, int y, ll z){
		update(0, 1, SZ, x, y, z);
	}
	void update(int idx, int s, int e, int x, int y, ll z){
		calc(idx);
		if(x<=s && e<=y){
			seg[idx].sum += z * seg[idx].cnt;
			seg[idx].lazy += z;
			return;
		}else if(x>e || y<s)	return;
		update(seg[idx].l, s, (s+e)/2, x, y, z);
		update(seg[idx].r, (s+e)/2+1, e, x, y, z);
		seg[idx].sum = seg[seg[idx].l].sum + seg[seg[idx].r].sum;
	}
	void Remove(int x, ll y){
		rmv(0, 1, SZ, x, y);
	}
	void rmv(int idx, int s, int e, int x, ll y){
		calc(idx);
		seg[idx].cnt--;
		seg[idx].sum -= y;
		if(s==e){
			return;
		}
		if(x<=(s+e)/2){
			rmv(seg[idx].l, s, (s+e)/2, x, y);
		}else{
			rmv(seg[idx].r, (s+e)/2+1, e, x, y);
		}
	}
	ll Sum(int x, int y){
		return sum(0, 1, SZ, x, y);
	}
	ll sum(int idx, int s, int e, int x, int y){
		calc(idx);
		if(x<=s && e<=y)	return seg[idx].sum;
		else if(x>e || y<s)	return 0;
		return sum(seg[idx].l, s, (s+e)/2, x, y) + sum(seg[idx].r, (s+e)/2+1, e, x, y);
	}
}Seg1, Seg2;

struct SEG2{
	struct NODE2{
		int l, r;
		int sum;
	};
	vector<NODE2> seg;
	int SZ;
	void add(){
		seg.pb({-1, -1, 0});
	}
	void Init(int x){
		SZ = x; add();
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
		seg[idx].sum++;
		if(s==e)	return;
		if(k<=(s+e)/2)	update(seg[idx].l, s, (s+e)/2, k);
		else	update(seg[idx].r, (s+e)/2+1, e, k);
	}
	int Sum(int x, int y){
		return sum(0, 1, SZ, x, y);
	}
	int sum(int idx, int s, int e, int x, int y){
		if(x<=s && e<=y)	return seg[idx].sum;
		else if(x>e || y<s)	return 0;
		return sum(seg[idx].l, s, (s+e)/2, x, y) + sum(seg[idx].r, (s+e)/2+1, e, x, y);
	}
} Seg;
int N;
int idx[MAX_N+1], arr[MAX_N+1];
ll ans = 0;
set<int> st;
set<int>::iterator it;

int main(){
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		scanf("%d", &arr[i]);
		idx[arr[i]] = i;
	}	
	Seg1.Init(N); Seg2.Init(N), Seg.Init(N);
	ll SW=0;
	int m = 0;
	for(int i=1; i<=N; i++){
		if(st.empty()){
			m = idx[i];
		}
		st.insert(idx[i]);
		Seg.Update(idx[i]);
		int t = Seg.Sum(1, m);
		if(t<(i+1)/2){
			it = st.upper_bound(m);
			m = (*it);
		}else if(t>(i+1)/2){
			it = st.lower_bound(m);
			it--; m = (*it);
		}
		TEST cout<<m<<endl;
		t = Seg.Sum(1, idx[i]);
		TEST cout<<t-1<<" "<<i-t<<endl;
		Seg1.Remove(idx[i], t-1); Seg2.Remove(idx[i], i-t);
		Seg2.Update(1, idx[i]-1, 1); Seg1.Update(idx[i]+1, N, 1);
		TEST cout<<"*"<<Seg2.Sum(N-1, N)<<endl;
		//TEST cout<<Seg1.Sum(idx[i]+1, N)<<" "<<Seg2.Sum(1, idx[i]-1)<<endl;
		TEST cout<<Seg1.Sum(1, m-1)<<" "<<Seg2.Sum(m+1, N)<<endl;
		ans = Seg1.Sum(1, m-1) + Seg2.Sum(m+1, N);
		SW += Seg.Sum(idx[i]+1, N);
		TEST cout<<SW<<endl;
		ans += SW;
		printf("%lld ", ans);
		TEST cout<<endl;
	}
	return 0;
}