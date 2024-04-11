#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define MOD 1000000007
#define INF (1ll<<62)
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int TC, N, M;
int A[101010];

int main(){
	scanf("%d", &TC);
	while (TC--){
		scanf("%d %d", &N, &M);
		if (N > M){
			puts("No");
			continue;
		}
		if (N & 1){
			puts("Yes");
			for (int i=1; i<N; i++) printf("1 ");
			printf("%d\n", M-N+1); 
		}
		else if (M & 1) puts("No");
		else{
			puts("Yes");
			for (int i=1; i<=N-2; i++) printf("1 ");
			printf("%d %d\n", (M-N+2)/2, (M-N+2)/2); 
		}
	}
	return 0;
}