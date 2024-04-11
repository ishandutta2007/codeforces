#include <bits/stdc++.h>



#define NN 1000011

#define MAX 10000000

using namespace std;

typedef long long INT;

typedef pair<int, int> pii;



INT sum[MAX+10];

int x[NN], prim[MAX+10], cnt[MAX+10], flag[MAX+10];



int main() {

	int n,m,i,j;

	scanf("%d", &n);

	for(i=0; i<n; i++) scanf("%d", x+i), flag[x[i]]++;

	scanf("%d", &m);

	

	int nn=0;

	for(i=2; i<=MAX; i++){

		if(prim[i]) continue;

		cnt[i]+=flag[i];

		for(j=i*2; j<=MAX; j+=i) prim[j]=1, cnt[i]+=flag[j];

	}

	

	

	for(i=1; i<=MAX; i++) sum[i]=sum[i-1]+cnt[i];

	

	

	while(m--){

		int l, r;

		scanf("%d %d" ,&l, &r);

		if(r>MAX) r=MAX;

		if(l>MAX) l=MAX;

		printf("%I64d\n", sum[r]-sum[l-1]);

	}



	return 0;

}