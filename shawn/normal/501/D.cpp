#include <bits/stdc++.h>

using namespace std;

const int maxn = 800005;  

int a[maxn] , b[maxn] , c[maxn] , v[maxn] , n;

int read () {
	int x = 0 , f = 1 , c = getchar();
	for ( ; c > '9' || c < '0' ; c = getchar() ) f = c == '-' ?-1 :1;
	for ( ; c >= '0' && c <= '9' ; c = getchar() ) x = x * 10 + c - 48;
	return x * f;
}

struct Bit {
	int t[maxn];
	void clear() {
		memset(t , 0 , sizeof t);
	}
	
	int getsum(int x){
		int ret = 0;
		for (int i = x ; i > 0; i -= i & -i) ret += t[i];
		return ret;
	}
	
	void add(int x , int f) {
		for (int i = x ; i <= n ; i += i & -i) t[i] += f;
	}
}B;

void cantor(int *a) {
	B.clear();
	for (int i = 1 ; i <= n ; i ++) {
		v[i] += (a[i] - 1 - B.getsum(a[i] - 1));
		B.add(a[i] , 1);
	}
}

int search(int x) {
	int l = 1 , r = n , ans = 0;
	while (l <= r) {
		int mid = l + r >> 1;
		if (mid - B.getsum(mid) >= x) ans = mid , r = mid - 1;
		else l = mid + 1;
	}
	return ans;
}

void recantor(int *a) {
	B.clear();
	for (int i = 1 ; i <= n ; i ++) a[i] = search(v[i] + 1) , B.add(a[i] , 1);
}

int main() {
	n = read();
	for (int i = 1 ; i <= n ; i ++) a[i] = read() + 1;
	for (int i = 1 ; i <= n ; i ++) b[i] = read() + 1;
	cantor(a);
	cantor(b);
	for (int i = n ; i ; i --) {
		v[i - 1] += v[i] / (n - i + 1);
		v[i] %= (n - i + 1);
	}
	recantor(c);
	for (int i = 1 ; i <= n ; i ++) printf("%d " , c[i] - 1);
	return 0;
}