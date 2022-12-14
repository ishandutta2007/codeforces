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
int A, B;

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &A, &B);
		if((A%2)!=(B%2)){
			printf("-1\n");
		}else{
			if(A==0 && B==0){
				printf("0\n");
			}else if(A==B || A==-B){
				printf("1\n");
			}else{
				printf("2\n");
			}
		}
	}
	return 0;
}