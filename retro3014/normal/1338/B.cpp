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

int N;
vector<int> gp[MAX_N+1];
int p[MAX_N+1];
int dp1[MAX_N+1];
bool tf1 = true;
int ans2;

void dfs(int x){
	dp1[x] = -1;
	int cnt1 = 0;
	for(int i : gp[x]){
		if(i==p[x])	continue;
		p[i] = x;
		dfs(i);
		if(gp[i].size()==1){
			cnt1++;
		}
		if(dp1[x]==-1){
			dp1[x]=dp1[i];
		}else{
			if(dp1[x]!=dp1[i]){
				tf1 = false;
			}
		}
	}
	if(cnt1>1){
		ans2-=(cnt1-1);
	}
	if(dp1[x]==-1)	dp1[x] = 0;
	else	dp1[x] = (1 ^ dp1[x]);
}

int main(){
	scanf("%d", &N);
	for(int i=1; i<N; i++){
		int a, b; scanf("%d%d", &a, &b);
		gp[a].pb(b); gp[b].pb(a);
	}
	int r; 
	ans2 = N-1;
	for(int i=1; i<=N; i++){
		if(gp[i].size()>1){
			r = i;
			break;
		}
	}
	dfs(r);
	if(tf1){
		printf("1 ");
	}else{
		printf("3 ");
	}
	printf("%d", ans2);
	return 0;
}