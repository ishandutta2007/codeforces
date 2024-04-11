#include <bits/stdc++.h>



#define NN 200111

using namespace std;

typedef long long INT;

typedef pair<int, int> pii;



INT a[NN], b[NN], nxt[NN];



void update(int p, int x){

	int nx=nxt[p];

	b[nx]+=x;

	int u=nx;

	while(1){

		if(b[u]<=a[u]) break;

		int rem=b[u]-a[u];

		b[u]=a[u];

		u=nxt[u+1];

		b[u]+=rem;

		nxt[u]=nxt[nxt[u]];

	}

	nxt[p]=u;

}



int main() {

	int n,m,i,j;

	cin>>n;

	for(i=1; i<=n; i++) scanf("%I64d", a+i), nxt[i]=i;

	a[n+1]=100000000000000000LL; nxt[n+1]=n+1;

	

	cin>>m;

	while(m--){

		int k, p, x;

		scanf("%d %d", &k, &p);

		if(k==1) scanf("%d", &x), update(p, x);

		else printf("%I64d\n", b[p]);

	}



	return 0;

}