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

int N, M;
set<pii> st;
vector<int> v;
vector<int> vt;

void dfs(int x){
	vt.pb(x);
	while(!vt.empty()){
		int now = vt.back(); vt.pop_back();
		int idx = 0;
		//cout<<now<<endl;
		while(idx<v.size()){
			if(st.find({now, v[idx]})!=st.end()){
				idx++;
			}else{
				//cout<<now<<" "<<v[idx]<<endl;
				vt.pb(v[idx]);
				int tmp = v.back(); v[v.size()-1] = v[idx]; v[idx] = tmp;
				v.pop_back();
			}
		}
	}
}

int main(){
	scanf("%d%d", &N, &M);
	for(int i=0; i<M; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		st.insert({a, b}); st.insert({b, a});
	}
	for(int i=1; i<=N; i++){
		v.pb(i);
	}
	int ans = -1;
	while(!v.empty()){
		ans++;
		int t = v.back();
		v.pop_back();
		dfs(t);
	}
	cout<<ans;
	return 0;
}