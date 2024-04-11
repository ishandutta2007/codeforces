#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

int main() {
	ull a, b;
    scanf("%I64u %I64u", &a, &b);
    if (a < b) puts("-1");
    else {
        a = (a - b) >> 1;
        if (a & b) puts("-1");
        else printf("%I64u %I64u\n", a, a ^ b);
    }
	return 0;
}