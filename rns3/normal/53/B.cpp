#include<bits/stdc++.h>
using namespace std;

int main(){
	long long h, w, x = 1, a = -1, b = -1;
	scanf("%I64d %I64d", &h, &w);
	for(int i = 0; i < 32; i ++) {
		if(x <= h && 4 * x <= 5 * w) {
			long long t = min(w, 5 * x / 4);
			if(x * t > a * b || (x * t  == a * b && a < x))
				a = x, b = t;
		}
		if(x <= w && 4 * x <= 5 * h) {
			long long t = min(h, 5 * x / 4);
			if(x * t > a * b||(x * t == a * b && a < t))
				a = t, b = x;
		}
		x <<= 1;
	}
	printf("%I64d %I64d\n", a, b);
	return 0;
}