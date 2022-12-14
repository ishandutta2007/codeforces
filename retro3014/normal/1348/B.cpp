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

int T;
int N, K;
vector<int> v, vt;
vector<int> ans;

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &N, &K);
		while(!v.empty())	v.pop_back();
		while(!vt.empty())	vt.pop_back();
		while(!ans.empty())	ans.pop_back();
		for(int i=0; i<N; i++){
			int x; scanf("%d", &x);
			v.pb(x); vt.pb(x);
		}
		sort(vt.begin(), vt.end());
		vt.erase(unique(vt.begin(), vt.end()), vt.end());
		if((int)vt.size()>K){
			printf("-1\n");
		}else{
			while(vt.size()<K){
				vt.pb(1);
			}
			int idx = 0;
			while(1){
				for(int i=0; i<vt.size(); i++){
					if(idx==(int)v.size())	break;
					ans.pb(vt[i]);
					if(v[idx]==vt[i])	idx++;
				}
				if(idx==(int)v.size()){
					break;
				}
			}
			printf("%d\n", (int)ans.size());
			for(int i : ans){
				printf("%d ", i);
			}printf("\n");
		}
	}
	return 0;
}