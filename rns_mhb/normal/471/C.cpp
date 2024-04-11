#include <bits/stdc++.h>
using namespace std;

long long n;
int k;

int main(){
	scanf("%I64d", &n), printf("%d", ((int)((sqrt(1 + 24.0 * n) - 1) / 6.0) + n % 3) / 3);
}