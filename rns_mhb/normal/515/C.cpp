#include <bits/stdc++.h>
using namespace std;
#define N 20
#define inf 1000000000
#define ep 1e-9
#define mp make_pair
#define pb push_back
template<class T> void chkmax(T &a, T b) {if (a < b) a = b;}
template<class T> void chkmin(T &a, T b) {if (a > b) a = b;}
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, a[N];
char d[N];

int main() {
	scanf("%d\n", &n);
	gets(d);
	for (int i = 0; i < n; i ++)
		if (d[i] > '1') a[d[i] - '0'] ++;
	for (int i = 8; i >= 2; i --) a[i] += a[i+1];
	a[2] += 2 * (a[4] - a[5]);
	a[4] = a[5];
	a[2] += a[6] - a[7];
	a[3] += a[6] - a[7];
	a[6] = a[7];
	a[3] += 2 * a[9];
	a[9] = 0;
	a[2] += 3 * a[8];
	a[8] = 0;

	a[10] = 0;
	for (int i = 9; i >= 2; i --)
		for (int j = a[i] - a[i+1]; j >= 1; j --) printf("%d", i);
    return 0;
}