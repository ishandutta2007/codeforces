#include <bits/stdc++.h>
#define pb push_back
#define all(v) v.begin(),v.end()
#define lb lower_bound
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int N;
LL A[202020];

int main(){
	scanf("%d", &N);
	LL mx=0;
	for (int i=1; i<=N; i++){
		scanf("%lld", &A[i]);
		printf("%lld ", A[i]+mx);
		mx = max(mx, A[i]+mx);
	}
	printf("\n");
	return 0;
}