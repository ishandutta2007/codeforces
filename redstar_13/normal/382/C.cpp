#include<bits/stdc++.h>



using namespace std;



int n, d, a[100010], i, ok;



int main(){

	

	scanf("%d", &n);

	for(i=0; i<n; i++) scanf("%d", a+i);

	

	sort(a, a+n);

	

	if(n==1) {puts("-1"); return 0;}

	

	d=a[1]-a[0];

	for(i=2; i<n; i++) d=min(d, a[i]-a[i-1]);

	

	if(d==0){

		for(i=1; i<n; i++) if(a[i]-a[i-1]) {puts("0"); return 0;}

		

		puts("1");

		printf("%d\n", a[0]);

		return 0;

	}

	

	if(n==2){

		if((a[0]+a[1])%2){

			puts("2");

			printf("%d %d\n", a[0]-d, a[1]+d);

			return 0;

		}

		puts("3");

		printf("%d %d %d\n", a[0]-d, (a[0]+a[1])>>1, a[1]+d);

		return 0;

	}



	for(i=1; i<n; i++){

		if(a[i]-a[i-1]==d) continue;

		if(a[i]-a[i-1]!=2*d) {puts("0"); return 0;}

		ok++;

	}



	if(!ok){

		puts("2");

		printf("%d %d\n", a[0]-d, a[n-1]+d);

		return 0;

	}



	if(ok==1){

		puts("1");

		for(i=1; i<n; i++){

			if(a[i]-a[i-1]==2*d){

				printf("%d\n", (a[i]+a[i-1])>>1);

				return 0;

			}

		}

	}



	puts("0");

	return 0;

}