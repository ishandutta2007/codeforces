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
const int MAX_N = 1001000;
 
int N, W, M;
vector<ll> v;
ll ans[MAX_N+1];
 
deque<pll> dq;
 
int main(){
	cin>>N>>W;
	for(int i=1; i<=N; i++){
		scanf("%d", &M);
		while(!v.empty())	v.pop_back();
		v.push_back(0);
		for(int i=1; i<=M; i++){
			ll x; scanf("%lld", &x);
			v.pb(x);
		}	
		v.push_back(0);
		for(int i=0; i<=M+1; i++){
			while(!dq.empty() && dq.front().second<i)	{
				ans[i]-=dq.front().first;
				dq.pop_front();
				if(!dq.empty()){
					ans[i]+=dq.front().first;
				}
			}
			if(dq.empty()){
				ans[i]+=v[i];
				dq.push_back({v[i], i+W-M});
			}else{
				ll prv = dq.front().first;
				 while(!dq.empty() && dq.back().first<=v[i]){
				 	dq.pop_back();
				 }
				 if(dq.empty()){
				 	ans[i]-=prv;
				 	ans[i]+=v[i];
				 }
				 dq.push_back({v[i], i+W-M});
			}
		}
		if(!dq.empty()){
			ans[M+2]-=dq.front().first;
		}
		ll lst = M+1;
		while(!dq.empty()){
			pll n = dq.front(); dq.pop_front();
			if(n.second>lst){
				ans[lst+1]+=n.first;
				ans[n.second+1]-=n.first;
				lst = n.second;
			}
		}
	}
	for(int i=1; i<=W; i++){
		ans[i] += ans[i-1];
		printf("%lld ", ans[i]);
	}
	return 0;
}