#include<bits/stdc++.h>



using namespace std;



int n, i, j, x[1010], a, b, c, d;



int main(){

	

	scanf("%d", &n);

	for(i=0; i<n; i++) scanf("%d", x+i);

	

	for(i=0; i<n-1; i++){

		for(j=0; j<n-1; j++){

			a=min(x[i], x[i+1]);

			b=max(x[i], x[i+1]);

			c=min(x[j], x[j+1]);

			d=max(x[j], x[j+1]);

			if((a<c&&c<b&&b<d) || (c<a&&a<d&&d<b)){

				puts("yes");

				return 0;

			}

		}

	}

	puts("no");

	return 0;

}