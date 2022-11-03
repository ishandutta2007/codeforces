/*
 * ID: Sfiction
 * OJ: CF
 * PROB: 443B
 */
#include <cstdio>
#include <cstring>

const int MAXL = 200 + 10;

int n, k;
char s[MAXL];

int main(){
	scanf("%s%d", s, &k);
	n = strlen(s);
	int i;
	for (i=(n+k)/2;i>k;--i){
		int l,r;
		for (l=n+k-2*i,r=l+i;s[r] && s[l] == s[r];++l,++r);
		if (!s[r])
			break;
	}

	int j;
	for (j=n/2;j>0;--j){
		int r0;
		for (r0=2*j;r0<n;++r0){
			int l,r;
			for (l=r0-2*j,r=r0-j;r<r0 && s[l]==s[r];++l,++r);
			if (r==r0)
				break;
		}
		if (r0<n)
			break;
	}
	printf("%d", (i > j ? i : j) << 1);

	return 0;
}