#include <bits/stdc++.h>

using namespace std;

#define N 100100

typedef long long LL;

int n, a[N];
LL b[N];


int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d%I64d", a + i, b + i);
	}
    int rt = 0, cur = -1;
    LL tp = 0;
    for(int i = 1; i <= n; i ++) {
    	b[i] = (b[i] + 3) >> 2;
    	a[i] ++;
    	while(b[i] > 1) {
    		b[i] = (b[i] + 3) >> 2;
			a[i] ++;
    	}
    	rt = max(rt, a[i]);
    }
	cout << rt << endl;
	return 0;
}