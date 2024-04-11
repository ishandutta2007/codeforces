#include <bits/stdc++.h>

using namespace std;

#define N 200100

struct pnt {
	int x, y, z;
	pnt (int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {}
	bool operator <(const pnt &a) const { return x != a.x ? x < a.x : y != a.y ? y > a.y : z < a.z; }
	bool operator ==(const pnt &a) const { return x == a.x && y == a.y && z == a.z; }
};

set <pnt> S;
int n, pr[N], nx[N], f[N], xx[N], yy[N], id[N];
string s[N];

int ok(int x, int y) {
	if((x > n) == (y > n)) return 1;
	return 0;
}

int lcp(string &a, string &b) {
	int la = a.length(), lb = b.length();
	int i = 0;
	for(;i < la && i < lb && a[i] == b[i]; i ++);
	return i;
}

bool cmp(int i, int j) { return s[i] < s[j]; }

void era(int a) {
	S.erase(pnt(ok(a, nx[a]), f[a], a));
}

void calc(int a, int b) {
	era(a);
	if(pr[a]) era(pr[a]);
	if(nx[b]) {
		era(b);
		if(pr[a]) {
			f[pr[a]] = min(min(f[pr[a]], f[a]), f[b]);
			S.insert(pnt(ok(pr[a], nx[b]), f[pr[a]], pr[a]));
		}
	}
	nx[pr[a]] = nx[b];
	pr[nx[b]] = pr[a];
}

int main() {

	ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	for(int i = 1; i <= 2 * n; i ++) {
		cin >> s[i];
		id[i] = i;
	}
	sort(id + 1, id + 2 * n + 1, cmp);
	for(int i = 1; i < 2 * n; i ++) {
		nx[id[i]] = id[i + 1]; pr[id[i + 1]] = id[i];
		int tp = ok(id[i], id[i + 1]);
		f[id[i]] = lcp(s[id[i]], s[id[i + 1]]);
		S.insert(pnt(tp, f[id[i]], id[i]));
	}
	long long rt = 0;
	for(int i = 1; i <= n; i ++) {
		set <pnt> :: iterator it;
		it = S.begin();
		rt += (*it).y;
		int a = (*it).z;
		xx[i] = a; yy[i] = nx[a];
		if(xx[i] > yy[i]) swap(xx[i], yy[i]);
		calc(a, nx[a]);
	}
	cout << rt << endl;
	for(int i = 1; i <= n; i ++) cout << xx[i] << " " << yy[i] - n << endl;
	return 0;
}