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

int N, T;
vector<int> vt;

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		vt.clear();
		while(N>0){
			vt.pb(N%10);
			N/=10;
		}
		reverse(vt.begin(), vt.end());
		if(vt.size()==1){
			printf("%d\n", vt.back());
		}else if(vt.size()==2){
			printf("%d\n", vt[1]);
		}else{
			int mn = 9;
			for(int i=0; i<vt.size(); i++){
				mn = min(mn, vt[i]);
			}
			printf("%d\n", mn);
		}
	}
	return 0;
}