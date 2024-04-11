#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int N, ans;
int a[10];

int main(){
	scanf("%d", &N);
	if (N & 1) ans += 16;
	if (N & 2) ans += 2;
	if (N & 4) ans += 8;
	if (N & 8) ans += 4;
	if (N & 16) ans += 1;
	if (N & 32) ans += 32;
	printf("%d\n", ans);
	return 0;
}