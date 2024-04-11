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
const int MAX_N = 300000;

int N, K;
string str;
vector<int> gp[MAX_N+1];
vector<int> group[MAX_N+1];

int g[MAX_N*2+1];
int dp[MAX_N*2+1];
bool chk[MAX_N*2+1];
int ans;

void ig(){
	for(int i=1; i<=K*2; i++){
		g[i] = i;
		if(i<=K)	dp[i] = 1;
	}
}

int fg(int x){
	return (x==g[x])?x:g[x]=fg(g[x]);
}

void ug(int x, int y){
	x = fg(x); y = fg(y);
	if(x==y)	return;
	g[y] = x;
	if(chk[y])	chk[x] = true;
	dp[x]+=dp[y];
}

void rmv(int x){
	int g1 = fg(x), g2 = fg(x+K);
	if(chk[g1]){
		ans-=dp[g1];
	}else if(chk[g2]){
		ans-=dp[g2];
	}else{
		ans-=min(dp[g1], dp[g2]);
	}
}

void add(int x){
	int g1 = fg(x), g2 = fg(x+K);
	if(chk[g1]){
		ans+=dp[g1];
	}else if(chk[g2]){
		ans+=dp[g2];
	}else{
		//cout<<g1<<" "<<g2<<" "<<dp[g1]<<" "<<dp[g2]<<endl;
		ans+=min(dp[g1], dp[g2]);
	}
}

int main(){
	scanf("%d%d", &N, &K);
	cin>>str;
	for(int i=1; i<=K; i++){
		int x; scanf("%d", &x);
		while(x--){
			int y; scanf("%d", &y);
			gp[i].pb(y);
			group[y].pb(i);
		}
	}
	ig();
	for(int i=1; i<=N; i++){
		// for(int j=1; j<=2*K; j++){
		// 	cout<<j<<" "<<g[j]<<" "<<dp[j]<<" "<<chk[j]<<endl;
		// }
		if(!group[i].empty()){
			if(group[i].size()==1){
				int t = group[i][0];
				//cout<<"*"<<t<<endl;
				rmv(t);
				if(str[i-1]=='0'){
					chk[fg(t)] = true;
				}else{
					chk[fg(K+t)] = true;
				}
				add(t);
			}else{
				int g1 = group[i][0], g2 = group[i][1];
				rmv(g1); 
				if(fg(g1)!=fg(g2) && fg(g1+K)!=fg(g2)) rmv(g2);
				if(str[i-1]=='0'){
					ug(g1, g2+K); ug(g1+K, g2);
				}else{
					ug(g1, g2); ug(g1+K, g2+K);
				}
				add(g1);
				if(fg(g1)!=fg(g2) && fg(g1+K)!=fg(g2))	add(g2);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}