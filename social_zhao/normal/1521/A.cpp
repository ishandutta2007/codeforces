#include <cstdio>
using namespace std;
#define ll long long

ll n, a, b;

ll read() {
	ll X = 0, F = 1; char C = getchar();
	while(C < '0' || C > '9') {if(C == '-')F=-1; C = getchar();}
	while(C >= '0' && C <= '9') {X = X*10+C-'0'; C = getchar();}
	return X * F;
}

int main() {
	ll T = read();
	while(T--) {
		/*
		6 3
		6 18 24
		*/
		a = read(); b = read();
		if(b == 1) puts("NO");
		else printf("YES\n%lld %lld %lld\n", a, a * b, a * (b + 1));
	}
	return 0;
}