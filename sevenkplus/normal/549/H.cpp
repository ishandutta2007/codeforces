#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

int a, b, c, d;

double gle(double l1, double r1, double l2, double r2) {
	double S = l1*l2;
	S = min(S, l1*r2);
	S = min(S, r1*l2);
	S = min(S, r1*r2);
	return S;
}

double gri(double l1, double r1, double l2, double r2) {
	double S = l1*l2;
	S = max(S, l1*r2);
	S = max(S, r1*l2);
	S = max(S, r1*r2);
	return S;
}

bool can(double x) {
	double le1 = gle(a-x,a+x,d-x,d+x);
	double ri1 = gri(a-x,a+x,d-x,d+x);
	double le2 = gle(b-x,b+x,c-x,c+x);
	double ri2 = gri(b-x,b+x,c-x,c+x);
	if (le1 > ri2 || le2 > ri1) return false;
	return true;
}

int main() {
	cin >> a >> b >> c >> d;
	double le = 0, ri = 1e9;
	for (int i = 0; i < 1000; i ++) {
		double mi = (le+ri)/2;
		if (can(mi)) ri = mi; 
		else le = mi;
	}
	printf ("%.9lf\n", (le+ri)/2);
	return 0;
}