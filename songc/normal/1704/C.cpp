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

int N, M, ans, TC;
int A[202020], B[202020];

int main(){
	scanf("%d", &TC);
	while (TC--){
		scanf("%d %d", &N, &M);
		int day = 0;
		for (int i=1; i<=M; i++) scanf("%d", &A[i]);
		sort(A+1, A+M+1);
		for (int i=2; i<=M; i++) B[i] = A[i] - A[i-1] - 1;
		B[1] = N - A[M] + A[1] - 1;
		sort(B+1, B+M+1);
		ans = 0;
		for (int i=M; i>0; i--){
			B[i] -= 2*day;
			if (B[i] <= 0) break;
			if (B[i] == 1) ans++, day++;
			else{
				ans += B[i] - 1;
				day += 2;
			}
		}	
		printf("%d\n", N-ans);
	}
	return 0;
}