#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1E5 + 10;

int a[MAXN];

int gcd(int a, int b){
	return b ? gcd(b, a % b) : a;
}

bool check23(int x){
	for (; !(x & 1); x >>= 1);
	for (; x % 3 == 0; x /= 3);
	return x == 1;
}

int main(){
	int n;
	scanf("%d", &n);
	int minVal = 1 << 30;
	for (int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
		minVal = min(minVal, a[i]);
	}
	bool flag = true;
	for (int i = 0; i < n; ++i){
		int d = gcd(minVal, a[i]);
		flag &= check23(minVal / d) && check23(a[i] / d);
	}
	puts(flag ? "Yes" : "No");
	return 0;
}