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
const int MAX_N = 200000;

int N, M, A, B;
vector<int> gp[MAX_N+1];
int T;
int chk[MAX_N+1];
bool vst[MAX_N+1];
vector<int> v;

void dfs(int x, int y){
	if(x==A || x==B)	return;
	chk[x]+=y;
	vst[x] = true;
	v.pb(x);
	for(int i : gp[x]){
		if(!vst[i]){
			dfs(i, y);
		}
	}
}

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d%d%d", &N, &M, &A, &B);
		for(int i=1; i<=M; i++){
			int a, b; scanf("%d%d", &a, &b);
			gp[a].pb(b); gp[b].pb(a);
		}
		for(int i : gp[A]){
			if(!vst[i])	dfs(i, 1);
		}
		for(int i=1; i<=N; i++)	vst[i] = false;

		for(int i : gp[B]){
			if(!vst[i])	dfs(i, 2);
		}
		for(int i=1; i<=N; i++)	vst[i] = false;
		ll TA=0, TB=0;
		for(int i=1; i<=N; i++){
			//cout<<i<<" "<<chk[i]<<endl;
			if(chk[i]==1){
				TA++;
			}else if(chk[i]==2){
				TB++;
			}
			chk[i] = 0;
		}
		for(int i=1; i<=N; i++){
			while(!gp[i].empty())	gp[i].pop_back();
		}
		printf("%lld\n", TA*TB);
	}
	return 0;
}