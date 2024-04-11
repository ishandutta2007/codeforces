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

int main(){
	scanf("%d", &TC);
	while (TC--){
		scanf("%d", &N);
		if (N == 0) puts("0");
		else if (N == 1) puts("2");
		else if (N == 2) puts("1");
		else if (N == 3) puts("1");
		else printf("%d\n", N/3 + (N % 3 != 0));
	}
	return 0;
}