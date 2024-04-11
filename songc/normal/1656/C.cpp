#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define lb lower_bound
#define MOD 1000000007
#define INF (1ll<<62)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int TC, N, K;
int A[101010];

int main(){
	scanf("%d", &TC);
	while (TC--){
		scanf("%d", &N);
		bool a=false;
		for (int i=1; i<=N; i++){
			scanf("%d", &A[i]);
			if (A[i] == 1) a = true;
		}
		if (!a){
			puts("YES");
			continue;
		}
		sort(A+1, A+N+1);
		a = false;
		for (int i=2; i<=N; i++) if (A[i] == A[i-1]+1) a = true;
		puts(a?"NO":"YES");
	}
	return 0;
}