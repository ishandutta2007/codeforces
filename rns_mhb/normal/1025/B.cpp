#include <bits/stdc++.h>
using namespace std;
#define inf 1000000000
#define ep 1e-9
#define mp make_pair
#define pb push_back
#define ll long long
#pragma comment(linker, "/STACK:1024000000,1024000000")
template<class T> void chkmax(T &a, T b) {if (a < b) a = b;}
template<class T> void chkmin(T &a, T b) {if (a > b) a = b;}
typedef pair<int, int> pii;
const double pi = 3.1415926535897932384626433832795028841971l;

#define N 50050
#define M 150050
int n, a[M], b[M];

int runs, p[N], phi[N];
void ppm() {
	phi[1] = 1;
	for (int i = 2; i < N; i ++) {
		if (!phi[i]) p[++runs] = i, phi[i] = i - 1;
		for (int j = 1; j <= runs && i * p[j] < N; j ++) {
			int k = i * p[j];
			phi[k] = phi[i] * (p[j] - 1);
			if (i % p[j] == 0) {
				phi[k] = phi[i] * p[j]; break;
			}
		}
	}
}

bool check(int c) {
	for (int i = 1; i <= n; i ++) {
		if ((a[i] % c) && (b[i] % c)) return 0;
	}
	return 1;
}

int main() {
	scanf("%d", &n);
	ppm();
	for (int i = 1; i <= n; i ++) scanf("%d%d", &a[i], &b[i]);
	for (int i = 1; i <= runs; i ++) {
		if (check(p[i])) {
			printf("%d\n", p[i]);
			return 0;
		}
	}
	for (int i = 1; i <= runs; i ++) {
		while (a[1] % p[i] == 0) a[1] /= p[i];
		if (a[1] == 1) break;
	}
	if (a[1] > 1 && check(a[1])) {
		printf("%d\n",a[1]);
		return 0;
	}
	for (int i = 1; i <= runs; i ++) {
		while (b[1] % p[i] == 0) b[1] /= p[i];
		if (b[1] == 1) break;
	}
	if (b[1] > 1 && check(b[1])) {
		printf("%d\n",b[1]);
		return 0;
	}
	puts("-1");
    return 0;
}