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
const int MAX_N = 1000;

int T;
int N, X;
vector<int> gp[MAX_N+1];

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &N, &X);
		for(int i=1; i<=N; i++)	{
			while(!gp[i].empty())	gp[i].pop_back();
		}
		for(int i=1; i<N; i++){
			int a, b; scanf("%d%d", &a, &b);
			gp[a].pb(b); gp[b].pb(a);
		}
		bool tf;
		if(gp[X].size()<=1){
			tf = true;
		}else{
			if(N%2){
				tf = false;
			}else{
				tf = true;
			}
		}
		if(tf){
			printf("Ayush\n");
		}else{
			printf("Ashish\n");
		}
	}
	return 0;
}