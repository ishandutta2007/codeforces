#include <cstdio>
#include <iostream>
using namespace std;

int main(){
//	freopen("cf1080b.in", "r", stdin);
//	freopen("cf1080b.out", "w", stdout);
	int q;
	long long l, r, ans;
	scanf("%d", &q);
	while(q--){
		cin >> l >> r;
		ans = 0;
		if((l & 1) == 0) ans += l, ++l;
		if(r & 1) ans -= r, --r;
//		printf("l = %d r = %d\n", l, r);
		ans += (r - l + 1) >> 1;
		cout << ans << endl;
	}
	return 0;
}