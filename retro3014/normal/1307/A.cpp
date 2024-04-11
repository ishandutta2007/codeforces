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
const int MAX_N = 100;
 
int T, N, D;
int arr[MAX_N+1];
 
int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &N, &D);
		for(int i=1; i<=N; i++){
			scanf("%d", &arr[i]);
			int d = (i-1);
			if(i==1)	continue;
			while(D>=d && arr[i]>0){
				D-=d;
				arr[1]++;
				arr[i]--;
			}
		}
		printf("%d\n", arr[1]);
 
	}	
	return 0;
}