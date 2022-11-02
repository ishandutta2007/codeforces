#include <bits/stdc++.h>

using namespace std;
#define x first
#define y second

typedef pair<int, int> pii;
typedef long long INT;

int dx[]={-1, 0, 1, 0};
int dy[]={0, 1, 0, -1};

int cnta[1111], cntb[1111];
int a[111], vst[111];

int calc_len(int n) {
	if (n==0) return 1;
	int res=0;
	while (n) {
		n/=7; res++;
	}
	return res;
}

int calc(int k, int la, int lb, int n, int m, int N, int M, int &res) {
	if (n>=N || m>=M) return 0;
	if (k==la+lb) {
		if (n<N && m<M) res++;
	} else {
		for (int i=0; i<7; i++) {
			if (vst[i]) continue;
			vst[i]=1;
			if (k<la) {
				calc(k+1, la, lb, n*7+i, m, N, M, res);
			} else calc(k+1, la, lb, n, m*7+i, N, M, res);
			vst[i]=0;
		}
	}
}

int main() {
	
	int N, M, b, i, nn, la, lb;
	int res;
	
	scanf("%d%d", &N, &M);
	
	la=calc_len(N-1); lb=calc_len(M-1);

	if (la+lb>7) {
		puts("0"); return 0;
	}
	
	memset(vst, 0, sizeof(vst));
	res=0;
	calc(0, la, lb, 0, 0, N, M, res);
	printf("%d\n", res);
}