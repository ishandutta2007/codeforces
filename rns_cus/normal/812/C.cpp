#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

#define N 100010

int a[N], n;
LL b[N], S, ans;

int main(){
//	freopen("in.txt", "r", stdin);
	scanf("%d %I64d", &n, &S);
	for(int i = 1; i <= n; i ++) scanf("%d", a + i);

	int st = 0, en = n + 1;
	while(st < en - 1){
		int mid = (st + en) >> 1;
		for(int i = 1; i <= n; i ++) b[i] = a[i] + (LL) mid * i;
		nth_element(b + 1, b + mid, b + n + 1);
		ans = 0;
		for(int i = 1; i <= mid; i ++) ans += b[i];
		if(ans > S) en = mid;
		else st = mid;
	}
	ans = 0;
	for(int i = 1; i <= n; i ++) b[i] = a[i] + (LL)st * i;
	nth_element(b + 1, b + st, b + n + 1);
	for(int i = 1; i <= st; i ++) ans += b[i];
	cout << st << " " << ans << endl;

}