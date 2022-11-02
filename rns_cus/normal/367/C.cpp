#include<bits/stdc++.h>
using namespace std;

#define N 2000400

int a[N], b[N], n, m, k;

int main(){
///	freopen("in.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i ++){
		scanf("%d %d", a + i, b + i);
	}
	for(int i = 1; i <= m; i ++){
		if(i & 1){
			int tmp = 1 + i * (i - 1) / 2;
			if(tmp <= n) k = i;
			else break;
		}
		else{
			int tmp = i * i / 2;
			if(tmp <= n) k = i;
			else break;
		}
	}

	//cout << k << endl;

	sort(b + 1, b + m + 1);

	long long sum = 0;
	for(int i = m; i > m - k; i --){
		sum += b[i];
	}
	cout << sum << endl;
}