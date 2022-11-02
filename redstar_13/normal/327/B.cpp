#include <bits/stdc++.h>



#define NN 100011

using namespace std;

typedef long long INT;

typedef pair<int, int> pii;



int vst[10000011], prim[10000111];



int main() {

	int n,i,j;

	cin>>n;

	int nn=0;

	for(i=2; i<=10000000; i++){

		if(vst[i]) continue;

		prim[nn++]=i;

		for(j=i*2; j<=10000000; j+=i) vst[j]=1;

	}

	for(i=0; i<n; i++) printf("%d ", prim[i]);





	return 0;

}