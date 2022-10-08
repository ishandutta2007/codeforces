#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef unsigned int uint;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long double db;
typedef complex<db> cp;

const db eps = 1e-12;

#define N 100010
int n;
string s;
int p[N], L;
bool a[N];

bool pr(int z) {
	for (int i = 0; p[i]*p[i] <= z; i ++)
		if (z%p[i] == 0) return false;
	return true;
}

int pow(int x, int y, int z) {
	int s = 1, t = x;
	while (y) {
		if (y&1) s = (ll)s*t%z;
		y /= 2;
		t = (ll)t*t%z;
	}
	return s;
}

int prim(int z) {
	vector<int> u;
	int z0 = z-1;
	for (int i = 0; p[i]*p[i] <= z0; i ++) {
		if (z0%p[i] == 0) {
			u.pb(p[i]);
			while (z0%p[i] == 0) z0 /= p[i];
		}
	}
	if (z0 != 1) u.pb(z0);
	int x = 2;
	while (true) {
		bool F = true;
		for (vector<int>::iterator i = u.begin(); i != u.end() && F; i ++)
			if (pow(x, (z-1)/(*i), z) == 1) F = false;
		if (F) return x;
		x++;
	}
}

int main() {
	for (int i = 2; i < N; i ++) {
		if (!a[i]) p[L++] = i;
		for (int j = 0; j < L && i*p[j] < N; j ++) {
			a[i*p[j]] = 1;
			if (i%p[j] == 0) break;
		}
	}
	
	cin >> n >> s;
	/*
	cp S(0, 0);
	for (int i = 0; i < n; i ++)
		S += cp(cos(2*i*M_PI/n), sin(2*i*M_PI/n))*cp(s[i]-'0',0);
	if (fabs(S.real()) < eps && fabs(S.imag()) < eps) puts ("YES");
	else puts ("NO");
	*/
	int cc = 0;
	for (int z = n+1; z < 1073741824 && cc < 10; z += n)
		if (pr(z)) {
			cc ++;
			//cout << z << endl;
			int c = pow(prim(z), (z-1)/n, z);
			int S = 0;
			int T = 1;
			
			for (int i = 0; i < n; i ++) {
				S = (S + (ll)T*(s[i]-'0'))%z;
				T = (ll)T*c%z;
				//cout << T << endl;
			}
			//puts ("");
			if (S) {
				puts ("NO");
				return 0;
			}
		}
	puts ("YES");
	return 0;
}