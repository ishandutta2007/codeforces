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
const int MAX_N = 300;

int T, N, M;
int arr[MAX_N+1][MAX_N+1];

int calc(int x, int y){
	if((x==1 || x==N) && (y==1 || y==M))	return 2;
	if(x==1 || x==N || y==1 || y==M)	return 3;
	return 4;
}

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &N, &M);
		bool tf = true;
		for(int i=1; i<=N; i++){
			for(int j=1; j<=M; j++){
				scanf("%d", &arr[i][j]);
				if(arr[i][j]>calc(i, j)){
					tf = false;
				}
				arr[i][j] = calc(i, j);
			}
		}
		if(!tf){
			printf("NO\n");
			continue;
		}else{
			printf("YES\n");
			for(int i=1; i<=N; i++){
				for(int j=1; j<=M; j++){
					printf("%d ", arr[i][j]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}