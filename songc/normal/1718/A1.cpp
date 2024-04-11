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
map<int,int> A;
int D[101010];

int main(){
	scanf("%d", &TC);
	while (TC--){
		A.clear();
		scanf("%d", &N);
		int x, s=0;
		A[0] = 0;
		for (int i=1; i<=N; i++){
			scanf("%d", &x);
			s ^= x;
			D[i] = D[i-1];
			if (A.find(s) != A.end()) D[i] = max(D[i-1], D[A[s]] + 1);
			A[s] = i;
		}
		printf("%d\n", N-D[N]);
	}
	return 0;
}