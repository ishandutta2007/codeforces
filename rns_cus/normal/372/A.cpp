#include<bits/stdc++.h>
using namespace std;

#define N 2000200

int a[N], n;


int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) scanf("%d", a + i);
	sort(a + 1, a + n + 1);
	//cout << n << endl;
	int mid = n / 2 + 1, tot = 0;
	int cur = mid;

	for(int i = 1; i < mid; i ++){
		while(a[cur] < 2 * a[i] && cur <= n) cur ++;
		if(a[cur] >= a[i] * 2){ tot ++; cur ++; }
	}
	cout << n - tot << endl;
}