#include <bits/stdc++.h>



#define NN 100011

using namespace std;

typedef long long INT;

typedef pair<int, int> pii;



char s[10][10];



int main() {

	int t,i,j;

	cin>>t;

	int x[4], y[4];

	while(t--){

		

		int k=0;

		for(i=0; i<8; i++) {

			scanf("%s", s+i);

			for(j=0; j<8; j++){

				if(s[i][j]=='K') x[k]=i, y[k++]=j;

			}

		}

		

		if(abs(x[0]-x[1])%4 || abs(y[0]-y[1])%4) {puts("NO"); continue;}

		puts("YES");

		

	}





	return 0;

}