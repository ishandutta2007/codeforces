#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

int dx[]={0, 0, 1, -1};
int dy[]={1, -1, 0, 0};

typedef pair<int, int> pii;
typedef long long INT;

template <class T> inline void smin(T &a, T b) {if (a>b) a=b;}
template <class T> inline void smax(T &a, T b) {if (a<b) a=b;}

INT C[111111], a[3][3], can[3][3];
int deg[3];
char s[1111111];

int pre() {
	C[0]=0;
	for (int i=1; i<100000; i++) C[i]=(INT) i*(i-1)/2;	
}

int OK(INT c0, INT c1, INT a01, INT a10, char s[1111111]) {
	INT i, k, r;
	memset(s, 0, sizeof(s));
	
	if (a01+a10!=c0*c1) return 0;
	
	if (c0==0) {
		if (c1==0) return 0;
		for (i=0; i<c1; i++) s[i]='1';
		return 1;
	}
	if (c1==0) {
		if (c0==0) return 0;
		for (i=0; i<c0; i++) s[i]='0';
		return 1;	
	}

	int nn=0;
	
	k=a01/c1;
	r=a01-k*c1;
	c0-=k;
	if (c0<0) return 0;
	if (r) c0--;
	if (c0<0) return 0;
	
	for (i=0; i<k; i++) s[nn++]='0';
	for (i=0; i<c1-r; i++) s[nn++]='1';
	if (r) s[nn++]='0';
	for (i=0; i<r; i++) s[nn++]='1';
	for (i=0; i<c0; i++) s[nn++]='0';
	if (nn==0) return 0;
	return 1;
}

int main() {
	
	pre();
	
	int i, j, k, yes;

	for (i=0; i<2; i++) for (j=0; j<2; j++) scanf("%I64d", &a[i][j]);
	
	if (a[0][0]==0) {
		can[0][deg[0]++]=0; can[0][deg[0]++]=1; 
	} else {
		k=lower_bound(C, C+100000, a[0][0])-C;
		if (C[k]==a[0][0]) can[0][deg[0]++]=k;
	}
	
	if (a[1][1]==0) {
		can[1][deg[1]++]=0; can[1][deg[1]++]=1;
	} else {
		k=lower_bound(C, C+100000, a[1][1])-C;
		if (C[k]==a[1][1]) can[1][deg[1]++]=k;
	}
	
	yes=0;
	for (i=0; i<deg[0]; i++) {
		for (j=0; j<deg[1]; j++) {
			if (OK(can[0][i], can[1][j], a[0][1], a[1][0], s)) {
				yes=1;
				break;
			}
		}
		if (yes) break;
	}
	
	if (yes) puts(s);
	else puts("Impossible");

	return 0;
}