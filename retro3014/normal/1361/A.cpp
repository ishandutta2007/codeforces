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
const int MAX_N = 500000;

int N, M;
vector<int> gp[MAX_N+1];
int cnt[MAX_N+1];
vector<pii> vt;
bool chk[MAX_N+1];
vector<int> v;

int main(){
	scanf("%d%d", &N, &M);
	for(int i=1; i<=M; i++){
		int a, b; scanf("%d%d", &a, &b);
		gp[a].pb(b); gp[b].pb(a);
	}
	for(int i=1; i<=N; i++){
		int x; scanf("%d", &x);
		vt.pb({x, i});
	}
	sort(vt.begin(), vt.end());
	int prv = 0;
	for(int i=0; i<vt.size(); i++){
		int n = vt[i].second;
		if(vt[i].first!=prv){
			while(!v.empty()){
				chk[v.back()] = 0;
				v.pop_back();
			}
		}
		if(chk[n] || cnt[n]!=vt[i].first-1){
			printf("-1");
			return 0;
		}
		for(int j : gp[n])	{
			if(!chk[j]){
				v.pb(j);
				chk[j] = true;
				cnt[j]++;
			}
		}
		prv = vt[i].first;
	}
	for(int i=0; i<vt.size(); i++){
		printf("%d ", vt[i].second);
	}

	return 0;
}