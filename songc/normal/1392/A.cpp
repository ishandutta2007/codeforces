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

int main(){
	scanf("%d", &TC);
	while (TC--){
		int a, b=0, x;
		scanf("%d", &N);
		scanf("%d", &a);
		for (int i=2; i<=N; i++){
			scanf("%d", &x);
			if (a != x) b=1;
		}
		printf("%d\n", b?1:N);
	}
	return 0;
}