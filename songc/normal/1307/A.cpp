#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int Q, N, T, ans;
int A[110];

int main(){
	scanf("%d", &Q);
	while (Q--){
		scanf("%d %d", &N, &T);
		ans = 0;
		for (int i=1; i<=N; i++) scanf("%d", &A[i]);
		for (int i=1; i<=N; i++){
			if (A[i]*(i-1) <= T){
				T -= A[i]*(i-1);
				ans += A[i];
			}
			else{
				ans += T/(i-1);
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}