#include <bits/stdc++.h>
#define fi first
#define se second
#define lb lower_bound
#define pb push_back
#define MOD 1000000007
#define INF (1ll<<60)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int TC, N;
LL F[110], S[110];
LL sum, A[110];

int main(){
	scanf("%d", &TC);
	F[0]=F[1]=S[0]=1, S[1]=2;
	for (int i=2; i<=60; i++) F[i]=F[i-1]+F[i-2], S[i] = S[i-1]+F[i];
	while (TC--){
		sum = 0;
		scanf("%d", &N);
		for (int i=1; i<=N; i++) scanf("%d", &A[i]), sum+=A[i];
		int k = -1;
		for (int i=0; i<=60; i++) if (S[i] == sum) k = i;
		if (k < 0){
			puts("NO");
			continue;
		}
		int pv=0;
		while (k >= 0){
			int mx=1;
			for (int i=1; i<=N; i++) if (A[i] > A[mx] || (A[i] == A[mx] && mx == pv)) mx = i;
			if (mx == pv || A[mx] < F[k]) break;
			pv = mx;
			A[mx] -= F[k];
			k--;
		}
		puts((k < 0) ? "YES" : "NO");
	}
	return 0;
}