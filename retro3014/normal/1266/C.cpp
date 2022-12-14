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
const int MAX_N = 500;

int N, M;
int arr[MAX_N+1][MAX_N+1];

int main(){
	scanf("%d%d", &N, &M);
	if(N==1 && M==1){
		printf("0");
		return 0;
	}
	if(N==1){
		for(int i=1; i<=M; i++){
			printf("%d ", i+1);
		}
		return 0;
	}else if(M==1){
		for(int i=1; i<=N; i++){
			printf("%d\n", i+1);
		}
		return 0;
	}
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			arr[i][j] = i * (N+j);
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}