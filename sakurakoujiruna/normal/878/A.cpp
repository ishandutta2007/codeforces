#include <bits/stdc++.h>
using namespace std;

int t[10];


int main() {
	int n; cin >> n;
	while(n --) {
		char c; int x;
		scanf("%c%c%d", &c, &c, &x);
		for(int i = 0; i < 10; i ++) {
			int y = (x >> i) & 1;
			if(c == '&' && y == 0)
				t[i] = 1;
			if(c == '|' && y == 1)
				t[i] = 2;
			if(c == '^' && y == 1)
				t[i] = 3 - t[i];
		}
	}
	cout << 3 << '\n';
	int a = 0, b = 0, c = 0;
	for(int i = 0; i < 10; i ++) {
		if(t[i] != 1)
			a |= (1 << i);
		if(t[i] == 2)
			b |= (1 << i);
		if(t[i] == 3)
			c |= (1 << i);
	}
	cout << "& " << a << '\n';
	cout << "| " << b << '\n';
	cout << "^ " << c << '\n';
}