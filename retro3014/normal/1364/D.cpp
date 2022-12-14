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

int N, M, k;
vector<int> gp[MAX_N+1];

int p[MAX_N+1], lv[MAX_N+1];
vector<int> ans;
int type;
vector<int> cycle;
bool vst[MAX_N+1];

void dfs(int x){
	vst[x] = true;
	for(int i : gp[x]){
		if(i==p[x])	continue;
		if(vst[i]){
			int n = x;
			while(1){
				cycle.pb(n);
				if(n==i)	break;
				n = p[n];
			}		
			return;
		}
		p[i] = x;	lv[i] = 1-lv[x];
		dfs(i);
		if(!cycle.empty())	return;
	}
}

vector<int> v1, v2;

int main(){
	scanf("%d%d%d", &N, &M, &k);
	for(int i=1; i<=M; i++){
		int a, b; scanf("%d%d", &a, &b);
		gp[a].pb(b); gp[b].pb(a);
	}
	dfs(1);
	if(cycle.empty()){
		for(int i=1; i<=N; i++){
			if(lv[i]){
				v1.pb(i);
			}else{
				v2.pb(i);
			}
		}
		k = (k+1)/2;
		type = 1;
		if(v1.size()>=k){
			while(ans.size()<k){
				ans.pb(v1.back()); v1.pop_back();
			}
		}else{
			while(ans.size()<k){
				ans.pb(v2.back()); v2.pop_back();
			}
		}
	}else{
		for(int i=1; i<=N; i++)	vst[i] = false;
		type = 1;
		for(int i=0; i<k; i++){
			for(int j : gp[cycle[i]]){
				if(!v1.empty() && j==v1.back())	continue;
				if(vst[j]){
					type = 2;
					for(int t=0; t<v1.size(); t++){
						ans.pb(v1[t]);
					}
					ans.pb(cycle[i]);
					break;
				}
			}
			if(type==2)	break;
			v1.pb(cycle[i]);
			vst[cycle[i]] = true;
		}
		if(type==1){
			k = (k+1)/2;
			for(int i=0; i<k; i++){
				ans.pb(v1[i*2]);
			}
		}
	}
	printf("%d\n", type);
	if(type==2){
		printf("%d\n", (int)ans.size());
	}
	for(int i : ans){
		printf("%d ", i);
	}
	return 0;
}