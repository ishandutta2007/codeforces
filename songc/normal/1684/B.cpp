#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define lb lower_bound
#define MOD 1000000007
#define INF (1ll<<62)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int Q;
int A[110];
char str[101010];

int main(){
	scanf("%d", &Q);
	for (int i=1; i<=Q; i++){
		LL a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);
		printf("%lld %lld %lld\n", a+((c-a)/b+1)*b, b, c);
	}
	return 0;
}