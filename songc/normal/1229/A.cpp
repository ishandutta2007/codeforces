#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int N;
LL ans, A[10101], B[10101];
vector<LL> V;

int main(){
	scanf("%d", &N);
	for (int i=1; i<=N; i++) scanf("%lld", &A[i]);
	for (int i=1; i<=N; i++) scanf("%lld", &B[i]);
	for (int i=1; i<=N; i++){
		for (int j=1; j<i; j++) if (A[j] == A[i]) {
			V.push_back(A[i]);
			break;
		}
	}
	for (int i=1; i<=N; i++){
		for (LL x : V){
			if ((A[i] | x) == x){
				ans += B[i];
				break;
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}