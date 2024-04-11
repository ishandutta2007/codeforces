#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int N;

int main(){
	scanf("%d", &N);
	while (N--){
		int x, t, a, b, tf=false;
		scanf("%d %d %d", &x, &a, &b);
		for (int i=1; i<=a; i++){
			scanf("%d", &t);
			if (t == x) tf = true;
		}
		for (int i=1; i<=b; i++){
			scanf("%d", &t);
		}
		if (tf) puts("YES");
		else puts("NO");
	}
	return 0;
}