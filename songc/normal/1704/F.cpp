#include <bits/stdc++.h>
#define fi first
#define se second
#define lb lower_bound
#define pb push_back
#define MOD 998244353
#define INF (1ll<<60)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int N, TC;
int D[110];
int mex[110];
char A[505050];

int sgv(int n){
	if (n <= 60) return D[n];
	return D[(n-60)%34 + 60];
}

int main(){
	for (int i=2; i<=100; i++){
		for (int j=0; j<=100; j++) mex[j] = 0;
		for (int j=0; j<i-1; j++) mex[D[j] ^ D[i-2-j]] = 1;
		for (int j=0; j<=100; j++) if (!mex[j]){
			D[i] = j;
			break;
		}
	}
	scanf("%d", &TC);
	while (TC--){
		scanf("%d", &N);
		scanf("%s", A+1);
		int x=0, r=0, b=0;
		int R=0, B=0;
		for (int i=1; i<=N; i++){
			if (A[i-1] == A[i]){
				if (r > b) R++;
				else if (r < b) B++;
				x ^= sgv(r+b);
				r=0, b=0;
			}
			if (A[i] == 'R') r++;
			else b++;
		}
		if (r > b) R++;
		else if (r < b) B++;
		x ^= sgv(r+b);

		if (x) R++;
		puts(R > B ? "Alice" : "Bob");
	}
	return 0;
}