#include <bits/stdc++.h>



#define NN 3333

using namespace std;

typedef long long INT;

typedef pair<int, int> pii;



int d[NN];



int main() {

	int n,m,i,j;

	cin>>n>>m;

	for(i=0; i<m; i++) scanf("%d", d+i);

	sort(d, d+m);

	if(d[0]==1 || d[m-1]==n) {puts("NO"); return 0;}

	int ok=1;

	for(i=2; i<m; i++) {

		if(d[i]==d[i-1]+1 && d[i-1]==d[i-2]+1) {ok=0; break;}

	}

	if(ok) puts("YES");

	else puts("NO");



	return 0;

}