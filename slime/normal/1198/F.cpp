#include <bits/stdc++.h>
#define maxn 100005
#define inf 200000
using namespace std;
int gcd(int x, int y) {
	if (!y) return x;
	return gcd(y, x % y);
}
struct th {
	int a, b;
}p[maxn];
int bl[maxn];
int pl[maxn];
int chs;
int ch[maxn][100], cc[maxn], tr[maxn];
int bpr[maxn];
int fl[maxn];
int rr[maxn];
int n;
void check(int t) {
	for (int i = 0; i < chs; i++)	
		if (t == tr[i]) return;
	tr[chs] = t;
	cc[chs] = 0;
	for (int i = 1; i <= n; i++)	
		if (p[i].a % t) {
			ch[chs][cc[chs]++] = p[i].b;
			if (cc[chs] >= 5) {
				chs--;
				break;
			}
		} 
	if (chs >= 0)
		for (int j = 0; j < cc[chs]; j++) 
			fl[ch[chs][j]] = 1;
//	cout << t << "!!!" << " " << cc[chs] << " " << ch[chs][0] << " " << ch[chs][1] << " " << fl[1] << endl;
	chs++;
}
int a[maxn];
int main() {
	srand(1903);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		p[i].b = i;
	//	if (i <= 20) 
		scanf("%d", &p[i].a);
	//	else p[i].a = 223092870;
		a[i] = p[i].a;
	}
	int fr = clock();
	int S = 40000;
	for (int i = 0; i < S; i++)
		bpr[i] = 1;

	for (int i = 2; i < S; i++) {
		if (!bpr[i]) continue;
		for (int j = 2; j * i < S; j++)
			bpr[i * j] = 0;
	}
	for (int t = 0; t < 50; t++) {
		int bf = 0;
		random_shuffle(p + 1, p + n + 1);
		for (int u = 1; u <= n; u++) {
			if (u % 10 == 1)
				bf = gcd(bf, p[u].a);
		}
		if (bf != 0) {
			for (int i = 2; i < S; i++) {
				if (bpr[i]) {
					if (bf % i) continue;
					check(i);
					while (!(bf % i)) bf /= i;
				}
			}
			if (bf != 1) check(bf);
		}
	}
	int rcnt = 0;
	for (int j = 1; j <= n; j++)
		if (fl[j]) rr[rcnt++] = j;
//	for (int j = 1; j <= 18; j++)
//		if (!fl[j]) cout << "???" << " " << j << endl;
//	cout << clock() - fr<< endl;
	int tms = 0;
	while(1) {
		tms++;
		if (!(tms % 20))
			if (1.0 * (clock() - fr) / CLOCKS_PER_SEC > 0.46) {
				printf("NO\n");
			//	cout << tms << " " << chs << " " << rcnt << endl;
				return 0;
			}
	//	cout << tms << " " << rcnt << endl;
		for (int j = 0; j < rcnt; j++)
			pl[rr[j]] = rand() & 1;
		int tp = 1;
		for (int j = 0; j < chs; j++) {
			int s = 0;
			for (int k = 0; k < cc[j]; k++)
				s += pl[ch[j][k]];
			if (s == 0 || s == cc[j]) tp = 0;
		}
		if (!tp) continue;
	//	cout << "AFAF" << endl;
		int l = 1, r = n;
		for (int j = 1; j <= n; j++) 
			if (fl[j])
				if (!pl[j]) p[l].a = a[j], p[l++].b = j;
				else p[r].a = a[j], p[r--].b = j;
		int lq = l;
		for (int j = 1; j <= n; j++) {
			if (!fl[j]) 
				p[l].a = a[j], p[l++].b = j;
		}
		if (lq < r)
			random_shuffle(p + lq, p + r + 1);
		int f = 0, k = 1;
		for (k = 1; k <= n; k++) {
			f = gcd(f, p[k].a);
			if (f == 1) break;
		}
		f = 0;
		for (int r = k + 1; r <= n; r++) 
			f = gcd(f, p[r].a);
		if (f == 1) {
			cout << "YES" << endl;
			for (int j = 1; j <= n; j++) {
				if (j <= k) bl[p[j].b] = 1;
				else bl[p[j].b] = 2;
			}
			for (int j = 1; j <= n; j++)
				printf("%d ", bl[j]);
			return 0;
		}
	} 
	return 0;
} 
/*
100000
111546435 111546435 74364290 74364290 44618574 44618574 31870410 31870410 20281170 20281170 17160990 17160990 13123110 13123110 11741730 11741730 9699690 9699690 223092870 223092870 223092870 223092870 223092870 223092870 223092870 223092870 223092870
*/