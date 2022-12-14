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

int Q;
set<int> st;
int last = 0;
map<int, int> g, d;

vector<int> v;
void find_g(int x){
	while(x != g[x]){
		v.pb(x);
		x = g[x];
	}
	while(!v.empty()){
		d[v.back()] = (d[g[v.back()]] ^ d[v.back()]);
		g[v.back()] = x;
		v.pop_back();
	}
}

int calc_dist(int x, int y){
	if(st.find(x)==st.end() || st.find(y)==st.end()){
		return -1;
	}
	find_g(x); find_g(y);
	if(g[x]!=g[y]){
		return -1;
	}
	return (d[x] ^ d[y]);
}

int main(){
	scanf("%d", &Q);
	for(int i=1; i<=Q; i++){
		int t;
		scanf("%d", &t);
		if(t==1){
			int l, r, x;
			scanf("%d%d%d", &l, &r, &x);
			l = (l ^ last);
			r = (r ^ last);
			x = (x ^ last);
			if(l > r){
				int tmp = l; l = r; r = tmp;
			} l--;
			if(st.find(l)==st.end()){
				st.insert(l);
				g[l] = l;
				d[l] = 0;
			}
			if(st.find(r)==st.end()){
				st.insert(r);
				g[r] = r;
				d[r] = 0;
			}
			int c = calc_dist(l, r);
			if(c==-1){
				find_g(l); find_g(r);
				x = (x ^ d[l]); x = (x ^ d[r]);
				l = g[l]; r = g[r];
				g[r] = l; d[r] = x;
			}
		}else{
			int l, r;
			scanf("%d%d", &l, &r);
			l = (l ^ last);
			r = (r ^ last);
			if(l>r){
				int tmp = l; l = r; r = tmp;
			} l--;
			int c = calc_dist(l, r);
			printf("%d\n", c);
			if(c==-1){
				last = 1;
			}else{
				last = c;
			}
		}
	}
	return 0;
}