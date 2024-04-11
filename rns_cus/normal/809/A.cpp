#include<bits/stdc++.h>
using namespace std;

#define N 300030

const int mod = 1e9 + 7;

int n, a[N];

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i ++) scanf("%d", a + i);
	sort(a, a + n);
	long long tmp = 1;
	long long sum = 0;
	for(int i = 1; i < n; i ++){
		sum = (sum + tmp * a[i]) % mod;
		tmp = (tmp * 2 + 1) % mod;
	}
	tmp = 1;
	for(int i = n - 2; i >= 0; i --){
		sum = (sum + mod - (tmp * a[i]) % mod) % mod;
		tmp = (tmp * 2 + 1) % mod;
	}
	cout << sum << endl;
}