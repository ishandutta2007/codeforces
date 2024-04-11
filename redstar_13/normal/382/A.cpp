#include <bits/stdc++.h>



#define NN 1000111

using namespace std;

typedef long long INT;

typedef pair<int, int> pii;



char s[NN], t[NN];



int main() {



	

	scanf("%s", s); 

	int n=strlen(s), i, j;

	int cnl=0, cnr=0;

	

	for(i=0; i<n; i++){

		if(s[i]=='|') break;

	}

	int pos=i;

	cnl=i, cnr=n-i-1;

	scanf("%s", t);

	int m=strlen(t);

	int d=abs(cnl-cnr);

	if(m<d || (m-d)%2) puts("Impossible");

	else {

		for(i=0; i<(m+n-1)/2-cnl; i++) putchar(t[i]);

		for(i=0; i<n; i++) putchar(s[i]);

		for(i=(m+n-1)/2-cnl; i<m; i++) putchar(t[i]);

	}





	return 0;

}