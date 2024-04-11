#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int TC;

int main(){
	scanf("%d", &TC);
	while (TC--){
		LL N;
		scanf("%lld", &N);
		if (N > 14 && (N % 14 == 1 || N % 14 == 2 || N % 14 == 3 || N % 14 == 4 || N % 14 == 5 || N % 14 == 6)) puts("YES");
		else puts("NO");
	}
	return 0;
}