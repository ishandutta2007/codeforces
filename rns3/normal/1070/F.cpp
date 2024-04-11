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

int n;
char s[10];
vector<int>a, b, c, d;
int A, B, C, D;

void func(vector<int>&v) {
	sort(v.begin(), v.end());
	v.push_back(0);
	reverse(v.begin(), v.end());
	for (int i = 1; i < v.size(); i ++) v[i] += v[i-1];
}

int main() {
	scanf("%d", &n);
	for (int i = 1, x; i <= n; i ++) {
		scanf("%s %d", s, &x);
		if (!strcmp(s, "00")) a.push_back(x);
		else if (!strcmp(s, "10")) b.push_back(x);
		else if (!strcmp(s, "01")) c.push_back(x);
		else  d.push_back(x);
	}
	A = a.size();
	B = b.size();
	C = c.size();
	D = d.size();
	func(a), func(b), func(c), func(d);
	int ans = 0;
	int sum = c[C] + d[D];
	for (int i = 0; i <= B; i ++) {
		int j = min(C + D - i, i + D - C);
		j = min(j, A);
		if (j >= 0) chkmax(ans, sum + b[i] + a[j]);
	}
	sum = b[B] + d[D];
	for (int i = 0; i <= C; i ++) {
		int j = min(B + D - i, i + D - B);
		j = min(j, A);
		if (j >= 0) chkmax(ans, sum + c[i] + a[j]);
	}
	sum = c[C] + b[B];
	for (int i = 0; i <= D; i ++) {
		int j = min(B + i - C, C + i - B);
		j = min(j, A);
		if (j >= 0) chkmax(ans, sum + d[i] + a[j]);
	}
	printf("%d\n", ans);
    return 0;
}