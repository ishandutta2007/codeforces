#include <bits/stdc++.h>

using namespace std;

#define NN 111
#define mod 1000000007
typedef long long INT;

int n;
INT cof[NN][NN], a[NN];

int calc(INT mat[NN][NN], INT m) {
	int i, j, k;
	if (m==0) {
		for (i=0; i<n; i++) for (j=0; j<n; j++) {
			if (i==j) mat[i][j]=1;
			else mat[i][j]=0;
		}
		return 0;
	}
	INT tmp[NN][NN];
	
	calc(tmp, m/2);
	for (i=0; i<n; i++) for (j=0; j<n; j++) {
		mat[i][j]=0;
		for (k=0; k<n; k++) {
			mat[i][j]+=tmp[i][k]*tmp[k][j];
			mat[i][j]%=mod;
		}
	}
	
	if (m%2) {
		for (i=0; i<n; i++) for (j=0; j<n; j++) {
			tmp[i][j]=0;
			for (k=0; k<n; k++) {
				tmp[i][j]+=mat[i][k]*cof[k][j];
				tmp[i][j]%=mod;
			}
		}
		for (i=0; i<n; i++) for (j=0; j<n; j++) mat[i][j]=tmp[i][j];
	}
}

int main() {
	
	int i, j;
	INT tmp, mat[NN][NN], K;
	
	scanf("%d%I64d", &n, &K);
	for (i=0; i<n; i++) scanf("%I64d", a+i);
	memset(cof, 0, sizeof(cof));
	
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			tmp=a[i]^a[j];
			if (__builtin_popcountll(tmp)%3==0) cof[i][j]=1;
		}
	}
	
	calc(mat, K-1);
	INT res=0;
	for (i=0; i<n; i++) for (j=0; j<n; j++) {
		res+=mat[i][j]; res%=mod;
	}
	if (res<0) res+=mod;
	
	printf("%I64d\n", res);
	
	return 0; 
}