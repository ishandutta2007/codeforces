#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define L 2000100

char p[L], s[410];
char x[100];
int m;
bool res[4010], tmp[4010], bf;

int main() {
	int n, q, r, S, k, t, l, ll, i, j, u;
//	freopen ("E.in", "r", stdin);

	gets(p);
	n=strlen(p);
	gets(s);
	S=strlen(s);
	scanf("%d", &m);
	q=n/m, r=n%m, ll=m-r;
	if (n<S) {
		puts("0");
		return 0;
	}
	if (!q) {
		j=n;
		for (i=0; i<m; i++) tmp[i]=0;
		for (i=S-1; i>=0; i--) {
			for (j--; j>=0; j--) {
				if (s[i]==p[j]) {
					tmp[j]=1;
					break;
				}
			}
			if (j<0) {
				puts("0");
				return 0;
			}
		}
		for (i=0; i<m; i++) printf("%d", tmp[i]);
		puts("");
		return 0;
	}

	k=S/q;
	for (i=0; i<m; i++) res[i]=1;
	bf=0;
	while (1) {
		for (i=0; i<m; i++) tmp[i]=0;
		t=S-k*q;
		if (k<t) break;
		if (t>r || k>m) {
			k--;
			continue;
		}
		l=k-t;
		{
			j=n;
			for (i=S-1; i>=S-t; i--) {
				for (j--; j>=n-r; j--) {
					if (s[i]==p[j]) {
						for (u=1; u<=q; u++) {
							if (s[i-u*k]!=p[j-u*m]) break;
						}
						if (u<=q) tmp[j-n+r]=0;
						else {
							tmp[j-n+r]=1;
							break;
						}
					}
				}
				if (j<n-r) goto la;
			}
			j=n-r;
			for (i=S-t-1; i>=S-t-l; i--) {
				for (j--; j>=n-r-ll; j--) {
					if (s[i]==p[j]) {
						for (u=1; u<q; u++) {
							if (s[i-u*k]!=p[j-u*m]) break;
						}
						if (u<q) tmp[j-n+m+r]=0;
						else {
							tmp[j-n+m+r]=1;
							break;
						}
					}
				}
				if (j<n-r-ll) goto la;
			}
		}
		bf=1;
		for (i=0; i<m; i++) if (res[i]!=tmp[i]) break;
		if (i<m && res[i]>tmp[i]) for (i=0; i<m; i++) res[i]=tmp[i];
la:;
		k--;
	}
	if (bf) {
		for (i=0; i<m; i++) printf("%d", res[i]);
		puts("");
	} else puts("0");
	return 0;
}