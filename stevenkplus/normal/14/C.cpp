#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

#define repi(i,a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i)
const int inf = 1 << 30;
int x1, x2;
int y1, y2;

map<int,int> ymap, xmap;
bool check() {
	for(int i = 0; i < 4; ++i) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		if (a == c) {
			++ymap[a];
			if (b > d) swap(b, d);
			if (b == d) return false;
			++xmap[b];
			++xmap[d];
		} else if (b == d) {
			++xmap[b];
			if (a > c) swap(a, c);
			if (a == c) return false;
			++ymap[a];
			++ymap[c];
		} else return false;
	}
	repi(i, xmap) {
		if (i->second != 3) return false;
	}
	repi(i, ymap) {
		if (i->second != 3) return false;
	}
	return true;

}

int main() {
	if (check()) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	return 0;
}