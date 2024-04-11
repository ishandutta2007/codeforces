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

int TC, N;
pii A[550];
int chk[550];

int main(){
	scanf("%*d %d", &N);
	for (int i=1; i<=N; i++){
		printf("? ");
		for (int j=1; j<i; j++) printf("0");
		printf("1");
		for (int j=i+1; j<=N; j++) printf("0");
		printf("\n");
		fflush(stdout);
		scanf("%d", &A[i].fi);
		A[i].se = i;
	}
	sort(A+1, A+N+1);

	int s=0;
	printf("? ");
	for (int j=1; j<=N; j++) printf("1");
	printf("\n");
	fflush(stdout);
	scanf("%d", &s);

	for (int i=N; i>1; i--){
		printf("? ");
		for (int j=1; j<A[i].se; j++) printf(chk[j]?"0":"1");
		printf("0");
		for (int j=A[i].se+1; j<=N; j++) printf(chk[j]?"0":"1");
		printf("\n");
		fflush(stdout);
		int a=0;
		scanf("%d", &a);
		if (A[i].fi != s-a) chk[A[i].se]=2;
		else chk[A[i].se]=1;
		s = a;
	}
	s=0;
	for (int i=1; i<=N; i++) if (chk[A[i].se] <= 1) s += A[i].fi;
	printf("! %d\n", s);
	fflush(stdout);
	return 0;
}