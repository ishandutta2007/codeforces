#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

int n, k, c[1000005];

int main() {
	n = get(), k = get();
	for(int i = 1; i <= n; i++) c[i] = get();
	int tmp = sqrt(k);
	for(int i = 2; i <= tmp; i++) {
		if(k % i == 0) {
			int mul = 1;
			bool flag = 0;
			while(k % i == 0) mul *= i, k /= i;
			if(mul == 1) continue;
			for(int j = 1; j <= n && !flag; j++) flag |= (c[j] % mul == 0);
			if(!flag) { printf("No"); return 0; }
		}
	}
	bool flag = 0;
	for(int i = 1; i <= n && !flag; i++) flag |= (c[i] % k == 0);
	if(!flag) printf("No");
	else printf("Yes");
}