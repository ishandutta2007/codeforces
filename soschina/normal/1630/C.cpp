#include <cstdio>
#include <iostream>
using namespace std;
const int N = 2e5 + 1, L = 20;

int n, a[N], r[N], st[N][L], ans;

int getmax(int l, int r){
	if(r < l) return 0;
	int len = r - l + 1, m = 0;
	while((1 << (m + 1)) <= len)
		m++;
	return max(st[l][m], st[r - (1 << m) + 1][m]);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = n; i; i--){
		if(r[a[i]])
			st[i][0] = r[a[i]];
		else
			r[a[i]] = i;
	}
	for(int l = 1; l < L; l++)
		for(int i = 1; i + (1 << l) - 1 <= n; i++)
			st[i][l] = max(st[i][l - 1], st[i + (1 << (l - 1))][l - 1]);
	int l = 1, r = 0;
	while(l <= n){
		if(r < l){
			if(!st[l][0]) l++;
			else{
				r = st[l][0];
				ans += r - l - 1;
			}
		}else{
			int tmp = getmax(l + 1, r - 1);
			if(tmp > r){
				l = r, r = tmp;
				ans += r - l - 1;
			}
			else
				l = r + 1;
		}
	}
	printf("%d", ans);
	return 0;
}