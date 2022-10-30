#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long INT;

#define INF 0x3f3f3f3f3f3f3f3fLL

INT M;
 
INT calc(INT mid) {
	INT k, res=0; 
	for (k=2; ; k++) {
		res+=mid/(k*k*k);
		if (mid<(k*k*k)) break;
	}
	
	return res;
}

int main() {
	
	INT M, st, ed, mid;
	scanf("%I64d", &M);
	st=0; ed=INF;
	
	while (ed-st>1) {
		mid=(st+ed)/2;
		if (calc(mid)>=M) ed=mid;
		else st=mid;
	}
	
	
	if (calc(st)==M) printf("%I64d\n", st);
	else if (calc(ed)==M) printf("%I64d\n", ed);
	else puts("-1");
	
	return 0;
}