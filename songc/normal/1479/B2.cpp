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

int TC, N, ans;
int A[101010], chk[101010];
int R[101010];

int main(){
	scanf("%d", &N);
	ans = N;
	for (int i=1; i<=N; i++) scanf("%d", &A[i]), chk[i] = N+1;
	for (int i=N; i>0; i--) R[i] = chk[A[i]], chk[A[i]] = i;
	int a=N+1, b=N+1;
	for (int i=1; i<=N; i++){
		if (a == i){
			ans--;
			a = R[i];
			if (a > b) swap(a, b);
		}
		else{
			if (a > R[i]) b=a, a=R[i];
			else b = R[i];
		}
	}
	printf("%d\n", ans);
	return 0;
}