#include<bits/stdc++.h>



using namespace std;



int n, m, x, y, z, p, i, j, a[100010], b[100010], aa, bb;



int main(){

	

	scanf("%d%d%d%d%d%d", &n, &m, &x, &y, &z, &p);

	x%=4, y%=2, z%=4;

	

	for(i=0; i<p; i++) scanf("%d%d", a+i, b+i);

	

	for(i=0; i<x; i++){

		for(j=0; j<p; j++){

			aa=a[j], bb=b[j];

			a[j]=bb, b[j]=n-aa+1;

		}

		swap(n, m);

	}

	

	if(y) for(i=0; i<p; i++) b[i]=m-b[i]+1;

	

	for(i=0; i<z; i++){

		for(j=0; j<p; j++){

			aa=a[j], bb=b[j];

			a[j]=m-bb+1, b[j]=aa;

		}

		swap(n, m);

	}

	for(i=0; i<p; i++) printf("%d %d\n", a[i], b[i]);

	return 0;

}