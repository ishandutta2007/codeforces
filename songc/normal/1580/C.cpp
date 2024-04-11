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

int N, M, num;
int X[202020], Y[202020], D[202020];
int P[202020], I[202020];
bool chk[202020];
vector<int> U[202020];
int A[550][550], ans;

int main(){
	scanf("%d %d", &N, &M);
	for (int i=1; i<=N; i++) scanf("%d %d", &X[i], &Y[i]);
	for (int i=1; i<=M; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		if (a == 1){
			D[b] = i;
			if (X[b]+Y[b] <= 500){
				A[X[b]+Y[b]][(i+X[b])%(X[b]+Y[b])]++;
				A[X[b]+Y[b]][i%(X[b]+Y[b])]--;
				ans++;
			}
			else{
				P[b] = ++num;
				I[num] = b;
				if (i+X[b] <= M) U[i+X[b]].pb(num);
				if (i+X[b]+Y[b] <= M) U[i+X[b]+Y[b]].pb(-num);
				chk[num] = true;
			}
		}
		else{
			if (X[b]+Y[b] <= 500){
				A[X[b]+Y[b]][(D[b]+X[b])%(X[b]+Y[b])]--;
				A[X[b]+Y[b]][D[b]%(X[b]+Y[b])]++;
			}
			else chk[P[b]] = false;
			if ((i-D[b])%(X[b]+Y[b]) > X[b] || (i-D[b])%(X[b]+Y[b]) == 0) ans--;
		}
		for (int j=2; j<=500; j++) ans += A[j][i%j];
		for (int x : U[i]){
			if (x > 0){
				if (!chk[x]) continue;
				ans++;
				if (i+X[I[x]]+Y[I[x]] <= M) U[i+X[I[x]]+Y[I[x]]].pb(x);
			}
			else{
				x = -x;
				if (!chk[x]) continue;
				ans--;
				if (i+X[I[x]]+Y[I[x]] <= M) U[i+X[I[x]]+Y[I[x]]].pb(-x);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}