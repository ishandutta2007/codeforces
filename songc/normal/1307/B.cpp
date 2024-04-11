#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int Q, N, X;

int main(){
	scanf("%d", &Q);
	while (Q--){
		scanf("%d %d", &N, &X);
		int mx = 0;
		for (int i=1; i<=N; i++){
			int x;
			scanf("%d", &x);
			if (x == X) mx = -1;
			if (mx != -1) mx = max(mx, x);
		}
		if (mx == -1) puts("1");
		else if (X < mx) puts("2");
		else printf("%d\n", (X+mx-1)/mx);
	}
	return 0;
}