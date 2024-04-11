#include <bits/stdc++.h>
using namespace std;
#define M 500001

int a[M];

int main() {
    int n;
    scanf("%d", &n);
    long long sum = 0;
    int cnt = 0;
    for(int i = 1; i <= n; i ++) {
    	int x;
		scanf("%d", &x);
		if(x % 2 == 0) sum += x;
		else a[++cnt] = x;
    }
    sort(a + 1, a + cnt + 1);
    for(int i = cnt; i >= 2; i -= 2) {
    	sum += a[i];
		sum += a[i-1];
    }
    cout << sum << endl;
}