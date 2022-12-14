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
const int MAX_N = 1024;

int N, K;
int gnum;

bool add(int x){
	printf("? %d\n", x);
	fflush(stdout);
	char c;
	while(1){
		scanf("%c", &c);
		if(c=='Y') return true;
		else if(c=='N')	return false;
	}
}

void reset(){
	printf("R\n");
	fflush(stdout);
	return;
}

void printans(int x){
	printf("! %d\n", x);
	fflush(stdout);
	return;
}

bool chk[MAX_N+1];
vector<int> gp[MAX_N+1];

void dfs(int x){
	for(int i=(x-1)*K+1; i<=x*K; i++){
		if(add(i)){
			chk[i] = false;
		}
	}	
	if(gp[x].empty())	return;
	int t = gp[x].back();
	gp[x].pop_back();
	dfs(t);
}

int main(){
	scanf("%d%d", &N, &K);	
	if(K==1)	K++;
	K/=2;
	gnum = (N-1)/K+1;
	for(int i=1; i<=N; i++)	chk[i] = true;
	for(int i=2; i<=gnum; i++){
		for(int j=1; j<i; j++){
			gp[j].pb(i);
		}
	}
	for(int i=1; i<=gnum; i++){
		while(!gp[i].empty()){
			reset();
			dfs(i);
		}
	}
	int ans=0;
	for(int i=1; i<=N; i++){
		if(chk[i])	ans++;
	}
	printans(ans);
	return 0;
}