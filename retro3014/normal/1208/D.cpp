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

int N;
vector<ll> v;

struct SEG{
	struct NODE{
		int l, r;
		ll data;
	};
	vector<NODE> seg;
	int SZ;
	void add(){
		seg.pb((NODE){-1, -1, (ll)0});
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
	void Update(int x, ll y){
		update(0, 1, SZ, x, y);
	}
	void update(int idx, int s, int e, int x, ll y){
		seg[idx].data+=y;
		if(s==e)	return;
		if(x<=(s+e)/2)	update(seg[idx].l, s, (s+e)/2, x, y);
		else	update(seg[idx].r, (s+e)/2+1, e, x, y);
	}
	ll Sum(int x, int y){
		return sum(0, 1, SZ, x, y);
	}
	ll sum(int idx, int s, int e, int x, int y){
		if(x<=s && e<=y)	return seg[idx].data;
		else if(x>e || y<s)	return 0;
		return sum(seg[idx].l, s, (s+e)/2, x, y) + sum(seg[idx].r, (s+e)/2+1, e, x, y);
	}
};

SEG Seg;
vector<ll> ans;
set<int> st;

int main(){
	cin>>N;
	Seg.Init(N);
	for(int i=0; i<N; i++){
		ll x; scanf("%lld", &x);
		v.pb(x);
	}
	for(int i=1; i<=N; i++){
		Seg.Update(i, i);
		st.insert(i);
	}
	while(!v.empty()){
		ll x = v.back(); v.pop_back();
		int s = 1, e = N, m; 
		while(s<e){
			m = (s+e)/2+1;
			if(Seg.Sum(1, m-1)>x){
				e = m-1;
			}else{
				s = m;
			}
		}
		//cout<<s<<endl;
		s = (*st.lower_bound(s));
		st.erase(s);
		ans.pb(s);
		Seg.Update(s, -s);
	}
	while(!ans.empty()){
		printf("%d ", (int)ans.back()); ans.pop_back();
	}
	return 0;
}