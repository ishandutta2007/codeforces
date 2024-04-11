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
		scanf("%s", str+1);
		int t=1, mn=10;
		for (; str[t]; t++){
			A[t] = str[t]-'0';
			mn = min(mn, A[t]);
		}
		t--;
		if (t == 1) printf("%d\n", A[1]);
		else if (t == 2) printf("%d\n", A[2]);
		else printf("%d\n", mn);
	}
	return 0;
}