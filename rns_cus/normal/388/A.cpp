#include <bits/stdc++.h>
using namespace std;

#define N 100010

int n, a[N], vis[N];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) scanf("%d", a + i);
	sort(a + 1, a + n + 1);
	int cnt = 0, gas = 0, tot = 0;
	while(tot < n){
		cnt = 0;
		for(int i = 1; i <= n; i ++)if(!vis[i]){
			if(a[i] >= cnt){ cnt ++; tot ++; vis[i] = true; }
		}
		gas ++;
	}
	cout << gas << endl;
}