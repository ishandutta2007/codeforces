#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int N, K, M=1;
vector<int> V;

int main(){
	scanf("%d %d", &N, &K);
	for (int i=1; i<=K+1; i++){
		printf("? ");
		for (int j=1; j<=K+1; j++) if (i!=j) printf("%d ", j);
		printf("\n");
		fflush(stdout);
		int x;
		scanf("%*d %d", &x);
		V.push_back(x);
	}
	sort(V.begin(), V.end());
	for (int i=0; V[i+1] == V[i]; i++, M++);
	printf("! %d\n", K+1-M);
	return 0;
}