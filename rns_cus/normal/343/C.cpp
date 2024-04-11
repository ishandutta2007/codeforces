#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

#define N 200020

LL a[N], b[N];
int n, m;

bool OK(LL d){
	int cur = 0, pos = 0;
	while(cur < n){
		if(b[pos] >= a[cur]){
			while(b[pos] <= a[cur] + d && pos < m) pos ++;
		}
		else{
			if(d < (a[cur] - b[pos])){ return false; }
			LL tot = max( d - 2 * (a[cur] - b[pos]), (d - a[cur] + b[pos]) / 2);
			while(b[pos] <= a[cur] + tot && pos < m) pos ++;
		}
		if(pos == m) return true;
		cur ++;
	}
	//cout << cur << " " << pos << endl;
	return false;
}

int main(){
//	freopen("c.in", "r", stdin);
	scanf("%d %d", &n, &m);
//	cout << n << " " << m << endl;
	for(int i = 0; i < n; i ++) scanf("%I64d", a + i);
	for(int j = 0; j < m; j ++) scanf("%I64d", b + j);

	LL st = -1, en = 1ll << 40;
///	cout << st << endl;
	while(st < en - 1){
		LL mid = (st + en) >> 1;
	//	cout << OK(mid) << endl;
		if(OK(mid)) en = mid;
		else st = mid;
	}
	cout << en << endl;
}