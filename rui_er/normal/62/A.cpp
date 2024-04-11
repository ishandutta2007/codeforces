//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;

int a_l, a_r, b_l, b_r; 
bool f1(int a, int b) {
	return (a << 1) + 3 > b;
}
bool f2(int a, int b) {
	return a + 1 >= b;
}
bool judge() {
	bool a = f1(a_l, b_r);
	bool b = f2(b_r, a_l);
	bool c = f1(a_r, b_l);
	bool d = f2(b_l, a_r);
	return a && b || c && d;
}

int main() {
	scanf("%d%d%d%d", &a_l, &a_r, &b_l, &b_r);
	judge() ? puts("YES") : puts("NO");
	return 0;
}