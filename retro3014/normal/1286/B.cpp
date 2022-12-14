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
const int MAX_N = 2000;

int N;
int r;
int p[MAX_N+1], c[MAX_N+1], sz[MAX_N+1];
int in[MAX_N+1], out[MAX_N+1], cnt;
vector<int> gp[MAX_N+1];
int num[MAX_N+1];
bool tf = true;

void dfs(int x){
	in[x] = ++cnt;
	sz[x] = 1;
	for(int i : gp[x]){
		dfs(i);
		if(!tf)	return;
		sz[x]+=sz[i];
	}
	if(sz[x]-1<c[x])	{
		tf = false;
		return;
	}
	out[x] = cnt;
	int mn = 0;
	num[in[x]] = c[x]+1;
	for(int i : gp[x]){
		for(int j=in[i]; j<=out[i]; j++){
			num[j]+=mn;
			if(num[j]>=num[in[x]])	num[j]++;
		}
		mn+=sz[i];
	}

}

int main(){
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		int a, b; 
		scanf("%d%d", &a, &b);
		if(a==0)	r = i;
		else gp[a].pb(i);
		c[i] = b;
	}
	dfs(r);
	for(int i=1; i<=N; i++){
		if(sz[i]-1<c[i]){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	for(int i=1; i<=N; i++){
		printf("%d ", num[in[i]]);
	}
	return 0;
}