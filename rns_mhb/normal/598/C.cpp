#include<bits/stdc++.h>
using namespace std;

#define N 100010

int n;
struct pnt{
	int x, y, id;
	int operator ^ (const pnt a) const {return x * a.y - y * a.x;}
	int operator & (const pnt a) const {return x * a.x + y * a.y;}
	double dist() {return x * x + y * y;}
} p[N];
long double al[N];

bool cmp(pnt a, pnt b) {
//	if (a.y >= 0 && b.y < 0) return 1;
//	if (a.y < 0 && b.y >= 0) return 0;
//	if (a.y == 0 && b.y == 0) return a.x > b.x;
//	return (a ^ b) > 0;
	return al[a.id] < al[b.id];
}


const long double pi = 3.14159265358979323846264338327950288L;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d%d", &p[i].x, &p[i].y), p[i].id = i;
	for (int i = 1; i <= n; i ++) {
		al[i] = atan2(p[i].y, p[i].x);
	}
	sort(p + 1, p + n + 1, cmp);
	sort(al + 1, al + n + 1);
	long double mx = 1e18;
	p[n+1] = p[1], al[n+1] = al[1] + 2 * pi;
	int id;
	for (int i = 1; i <= n; i ++) {
		long double tmp = min(al[i+1] - al[i], 2 * pi - al[i+1] + al[i]);
		if (mx > tmp) mx = tmp, id = i;
	}
	cout<<p[id].id<<" "<<p[id+1].id<<endl;
}