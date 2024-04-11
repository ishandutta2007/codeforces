#include<bits/stdc++.h>
using namespace std;

#define N 100010

int ans, n, arr[N];
long long a, b, h, w, uu, vv;

const long long INF = 1e12;

void chkmin(int &x, int y){ if(x > y) x = y; }

long long pow(long long x, long long y){
	long long ret = 1;
	while(y){
		if(y & 1) ret = ret * x;
		x *= x;
		y >>= 1;
	}
}

void dfs(int dep, long long u, long long v){
	if(u >= a && v >= b){
		chkmin(ans, dep); return;
	}
	if(dep >= ans) return;
	if(dep == n) return;
	int gas = 0;
	for(int i = dep; i < n && arr[i] == arr[dep]; i ++) gas ++;

///	cout << "DEP " << dep << " " << arr[dep] << " " << gas << endl;

	int gas1 = 0,   gas2 = 0;
	uu = u,   vv = v;
	while(uu < a){ gas1 ++; uu *= arr[dep]; }
	while(vv < b){ gas2 ++; vv *= arr[dep]; }
////	cout <<"GAS  " <<  gas1 << " " << gas2 << endl;
	if(gas1 + gas2 <= gas){
//		cout << dep << endl;
//		cout << gas1 << " " << gas2 << endl;
		chkmin(ans, dep + gas1 + gas2); return;
	}
	else{
	///	cout << " UVD  " << dep << " " << u << " " << v << endl;
		for(int i = 0; i <= gas && i <= gas1; i ++){
			if(gas - i <= gas2){
				dfs(dep + gas, u * pow(arr[dep], i), v * pow(arr[dep], gas - i));
			}
		}
	///	puts("END");
	}
}

int main(){
///	freopen("a.in", "r", stdin);
	scanf("%I64d %I64d %I64d %I64d %d", &a, &b, &h, &w, &n);
	for(int i = 0; i < n; i ++) scanf("%d", arr + i);
	sort(arr, arr + n, greater<int>() );
	ans = n + 1;
	dfs(0, h, w);
	dfs(0, w, h);
	if(ans == n + 1) puts("-1");
	else cout << ans << endl;
}