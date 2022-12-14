#include <bits/stdc++.h>
using namespace std;

int main() {
	///freopen("4.in", "r", stdin);
	int a, b, c, d, e, f;
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
    if(a == c && a == e) return puts("1");
    if(b == d && b == f) return puts("1");
	if(a == c) {
        if(f <= min(b, d) || f >= max(b, d)) return puts("2");
	}
	if(a == e) {
		if(d <= min(b, f) || d >= max(b, f)) return puts("2");
	}
	if(c == e) {
		if(b <= min(d, f) || b >= max(d, f)) return puts("2");
	}
	if(b == d) {
		if(e <= min(a, c) || e >= max(a, c)) return puts("2");
	}
	if(b == f) {
		if(c <= min(a, e) || c >= max(a, e)) return puts("2");
	}
	if(d == f) {
        if(a <= min(c, e) || a >= max(c, e)) return puts("2");
	}
	return puts("3");
}