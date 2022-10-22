#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define Mup(a,x) a=max(a, x)
#define mup(a,x) a=min(a, x)
#define all(v) v.begin(),v.end()
#define lb lower_bound
#define INF (1ll<<60)
#define MOD 1'000'000'007 
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int N, Q;

int main(){
	scanf("%d", &N);
	for (int i=1; i<=N; i++){
		for (int j=1; j<=N; j++){
			printf("%lld", (i&1)?0:(1ll<<(i+j-3)));
			if (j!=N) printf(" ");
		}
		printf("\n");
	}
	fflush(stdout);

	scanf("%d", &Q);
	while (Q--){
		LL k;
		scanf("%lld", &k);
		int x=1, y=1;
		printf("1 1\n");
		for (int i=1; i<2*N-1; i++){
			if (x&1){
				if (k&(1ll<<(x+y-2))) x++;
				else y++;
			}
			else{
				if (k&(1ll<<(x+y-2))) y++;
				else x++;
			}
			printf("%d %d\n", x, y);
		}
		fflush(stdout);
	}
	return 0;
}