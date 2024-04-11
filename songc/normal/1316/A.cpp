#include <bits/stdc++.h>
#define pb push_back
#define all(v) v.begin(),v.end()
#define lb lower_bound
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int tc, N, M;

int main(){
	scanf("%d", &tc);
	while (tc--){
		int sum=0, x;
		scanf("%d %d", &N, &M);
		for (int i=1; i<=N; i++){
			scanf("%d", &x);
			sum += x;
		}
		printf("%d\n", min(sum, M));
	}
	return 0;
}