#include <bits/stdc++.h>
#define ll long long
#define maxn 400005 /*rem*/
#define mod 1000000007 
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
int fa[maxn], sz[maxn];
int gfa(int a) {
	if (fa[a] == a) return a;
	return fa[a] = gfa(fa[a]);
}
int c[maxn];
int cc(int a) {
	return a * (a - 1) / 2;
}
char p[maxn], t[maxn];
int a[maxn]; 
bool fl[maxn];
bool check(int c) {
	memset(fl, 0, sizeof(fl));
	int tl = strlen(t);
	for (int i = c; i < tl; i++)
		fl[a[i] - 1] = 1;
	int npl = 0;
	int pl = strlen(p);
	for (int i = 0; i < tl; i++) {
		if (!fl[i]) continue;
		if (t[i] == p[npl]) npl++;
	}
	if (npl >= pl) return 1;
	return 0;
}
int main() {
	scanf("%s%s", t, p);
	int l = strlen(t);
	for (int i = 0; i < l; i++)
		scanf("%d", &a[i]);
	int ls = 0, rs = l - 1;
	while (ls < rs) {
		// x ~ end
		int mid = (ls + rs) / 2;
		if (check(mid + 1)) ls = mid + 1;
		else rs = mid;
	}
	cout << ls << endl;
	return 0;
}