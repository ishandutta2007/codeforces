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

int T;
int N, M;
int A[MAX_N+1], B[MAX_N+1], C[MAX_N+1];
vector<int> vt[MAX_N+1];
vector<int> v;
int ans[MAX_N+1];

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &N, &M);
		v.clear();
		for(int i=1; i<=N; i++){
			vt[i].clear();
			scanf("%d", &A[i]);
		}
		for(int i=1; i<=N; i++){
			scanf("%d", &B[i]);
			if(B[i]==A[i]){
				vt[B[i]].pb(i);
			}
		}
		for(int i=1; i<=N; i++){
			if(B[i]!=A[i]){
				vt[B[i]].pb(i);
			}
		}
		for(int i=1; i<=M; i++){
			scanf("%d", &C[i]);
		}
		bool tf = true;
		for(int i=M; i>=1; i--){
			int c = C[i];
			if(vt[c].empty()){
				if(v.empty()){
					printf("NO\n");
					tf = false;
					break;
				}
				ans[i] = v.back();
			}else{
				int t = vt[c].back(); vt[c].pop_back();
				ans[i] = t;
				v.pb(t);
			}
		}
		if(tf){
			for(int i=1; i<=N; i++){
				while(!vt[i].empty()){
					int t = vt[i].back(); vt[i].pop_back();
					if(A[t]!=B[t]){
						tf = false;
						printf("NO\n");
						break;
					}
				}
				if(!tf)	break;
			}
			if(tf){
				printf("YES\n");
				for(int i=1; i<=M; i++){
					printf("%d ", ans[i]);
				}
				printf("\n");
			}
		}
		for(int i=1; i<=N; i++){
			vt[i].clear();
		}
	}
	return 0;
}