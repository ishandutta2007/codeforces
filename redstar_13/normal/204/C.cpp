#include<bits/stdc++.h>



#define NN 200011

using namespace std;

typedef long long INT;

typedef double DO;



char A[NN], B[NN];

INT s[2][NN], sum[30];



int main(){

	int n,i,j,k;

	cin>>n;

	

	scanf("%s%s", A+1, B+1);

	memset(s, 0, sizeof(s));

	for(i=1; i<=n; i++){

		sum[B[i]-'A']+=i;

		s[0][i]=sum[A[i]-'A'];

	}

	

	memset(sum, 0, sizeof(sum));

	

	for(i=n; i>=1; i--){

		s[1][i]=sum[A[i]-'A'];

		sum[B[i]-'A']+=n-i+1;

	}

	

	DO ans=0;

	

	INT tot=0;

	for(i=1; i<=n; i++) tot+=(INT)i*i;

	

	for(i=1; i<=n; i++) ans+=s[0][i]*(n-i+1)+s[1][i]*i;



	ans/=tot;

	printf("%.10lf\n", ans);

	return 0;

}