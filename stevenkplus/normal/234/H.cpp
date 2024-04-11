#include <cstdio>

using namespace std;

const int MAXN = 200100;

int ar1[MAXN];
int ar2[MAXN];

int flips[MAXN];
int fcnt = 0;

int N;
int M;

int a = 0;
int b = 0;
int fin[MAXN];
int numf = 0;

int prf = -1;
void put(int k) {
	int x;
	if (k == 0) {
		fin[numf++] = a + 1;
		x = ar1[a++];
	} else {
		fin[numf++] = N + b + 1;
		x = ar2[b++];
	}
	if (x != prf && prf != -1) {
		flips[fcnt++] = numf - 1;
	}
	prf = x;
}


int main() {
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);	
		freopen("output.txt", "w", stdout);
	}
	scanf("%d", &N);
	int fdiffs = 0;
	int pr = -1;
	for(int i = 0; i < N; ++i) {
		scanf("%d", ar1 + i);
		if (ar1[i] == 1 && pr == 0 || ar1[i] == 0 && pr == 1) {
			fdiffs++;
		}
		pr = ar1[i];
	}
	scanf("%d", &M);
	int sdiffs = 0;
	pr = -1;
	for(int i = 0; i < M; ++i) {
		scanf("%d", ar2 + i);
		if (ar2[i] == 1 && pr == 0 || ar2[i] == 0 && pr == 1) {
			sdiffs++;
		}
		pr = ar2[i];
	}
	if (fdiffs > sdiffs) {
		put(0);
	} else {
		put(1);
	}
	for(int i = 1; i < N + M; ++i) {
		bool x = a < N;
		bool y = b < M;
		if (x && y) {
			if (ar1[a] == ar2[b]) {
				y = false;
			} else if (ar1[a] == prf) {
				y = false;
			} else {
				x = false;
			}
		}
		if (x) {
			put(0);
		} else {
			put(1);
		}
	}
	if (prf == 1) {
		flips[fcnt++] = N + M;
	}
	for(int i = 0; i < N + M; ++i) {
		if (i > 0) {
			printf(" ");
		}
		printf("%d", fin[i]);
	}
	printf("\n");
	printf("%d\n", fcnt);
	for(int i = 0; i < fcnt; ++i) {
		if (i > 0) {
			printf(" ");
		}
		printf("%d", flips[i]);
	}
	printf("\n");
	return 0;
}