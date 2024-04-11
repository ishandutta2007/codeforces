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
vector<int> v;
 
set<int> st;
 
int ans = INF;
 
int main(){
	cin>>N;
	for(int i=0; i<N; i++){
		int x; scanf("%d", &x);
		v.pb(x);
	}
	int idx = N;
	for(int i=N-1; i>=0; i--){
		if(st.find(v[i])!=st.end()){
			break;
		}
		st.insert(v[i]);
		idx = i;
	}
	ans = min(ans, N-(int)st.size());
	for(int i=0; i<N; i++){
		while(st.find(v[i])!=st.end() && idx<N){
			st.erase(v[idx]);
			idx++;
		}
		if(st.find(v[i])!=st.end())	break;
		st.insert(v[i]);
		ans = min(ans, N-(int)st.size());
	}
	printf("%d", ans);
	return 0;
}