#include<bits/stdc++.h>
using namespace std;

#define N 100010

int h[N][7], w[N][7], n, m;
const long long INF = 1ll<<60;
long long f[40];
template <class T> void chkmin(T &a, T b){ if(a > b) a = b; }

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i < m; i ++)
		for(int j = 0; j < n; j ++) scanf("%d", w[i] + j);

	for(int i = 0; i < m; i ++)
		for(int j = 0; j < n; j ++) scanf("%d", h[i] + j);

	int sz = 1 << n;
	for(int i = 1; i < sz; i ++) f[i] = INF;
	for(int i = 1; i < m; i ++){
		for(int j = 0; j < sz; j ++){
			for(int k = 0; k < n; k ++)
				if(!(j & (1 << k))) chkmin(f[j^(1 << k)], f[j] + w[i][k]);
			for(int k = 0; k < n; k ++)
				if(((j>>k)^(j>>(k+1)%n))&1) f[j] += h[i][k];
		}
	}
	cout << f[sz - 1] << endl;
}