#include <set>
#include <cstdio>
#include <algorithm>

using namespace std;

int p[3];

multiset <int> S;
multiset <int> :: iterator pos, it;

void Kill(int v) {
	if (S.empty()) return;
	it = S.upper_bound(v);
	if (it == S.begin()) return;
	it --;
	S.erase(it);
}

main() {
    int n, mx = 0;
    scanf("%d", &n);
    for (int i = 0; i < 3; i ++) scanf("%d", p + i);
    for (int i = 0; i < n; i ++) {
    	int a;
		scanf("%d", &a);
		if (a > mx) mx = a;
		S.insert(a);
    }
    sort(p, p + 3);
    if (mx > p[0] + p[1] + p[2]) return puts("-1");
    int rlt = 0;
    while (!S.empty()) {
		rlt ++;
		pos = S.end(); pos --;
		int biggest = *pos;
		S.erase(pos);
		if (biggest <= p[2]) {
			it = S.begin();
			if (it == S.end()) break;
			if (p[0] < *it) Kill(p[0] + p[1]);
			else Kill(p[1]), Kill(p[0]);
		} else if (biggest <= p[0] + p[1]) Kill(p[2]);
		else if (biggest <= p[0] + p[2]) Kill(p[1]);
		else if (biggest <= p[1] + p[2]) Kill(p[0]);
    }
    printf("%d\n", rlt);
}