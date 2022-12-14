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

int T, N;
int A[MAX_N+1];
bool chk[MAX_N+1];
int ans;
int B[MAX_N+1];
vector<int> vt, v, v2;

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		vt.clear(); v.clear(); v2.clear();
		ans = 0;
		for(int i=1; i<=N; i++)	chk[i] = false;
		for(int i=1; i<=N; i++){
			scanf("%d", &A[i]);
			if(chk[A[i]]){
				vt.pb(i);
			}else{
				ans++;
				B[i] = A[i];
				chk[A[i]] = true;
			}
		}
		if(vt.size()==1 && !chk[vt.back()]){
			B[vt.back()] = A[vt.back()];
			for(int i=1; i<=N; i++){
				if(i==vt.back())	continue;
				if(B[i]==B[vt.back()]){
					B[i] = vt.back();
				}
			}
		}else if(!vt.empty()){
			while(!vt.empty()){
				if(chk[vt.back()]){
					v.pb(vt.back());
				}else{
					v2.pb(vt.back());
				}
				vt.pop_back();
			}
			if(v.empty()){
				v.pb(v2.back());
				v2.pop_back();
			}
			while(!v2.empty()){
				B[v.back()] = v2.back();
				chk[v2.back()] = true;
				v.pop_back();
				v.pb(v2.back()); v2.pop_back();
			}
			int idx = 1;
			while(!v.empty()){
				while(chk[idx]) idx++;
				B[v.back()] = idx;
				idx++;
				v.pop_back();
			}
		}
		printf("%d\n", ans);
		for(int i=1; i<=N; i++){
			printf("%d ", B[i]);
		}printf("\n");
	}
	return 0;
}