#include <cstdio>
#include <iostream>
using namespace std;
const int N = 2e5 + 1, L = 20;

int gcd(int a, int b){
	return b ? gcd(b, a % b) : a;
}

int n, st[N][L];
int bd[N];
int getgcd(int l, int r){
	int i = bd[r - l + 1];
	return gcd(st[l][i], st[r - (1 << i) + 1][i]);
}

int ans, last;

int main(){
	scanf("%d", &n);
	for(int i = 0; (1 << i) <= n; i++){
		int l = 1 << i, r = 1 << (i + 1);
		for(int j = min(r - 1, n); j >= l; j--)
			bd[j] = i;
	}
	for(int i = 1; i <= n; i++)
		scanf("%d", &st[i][0]);
	for(int j = 1; j < L; j++)
		for(int i = 1; i + (1 << j) - 1 <= n; i++)
			st[i][j] = gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
	for(int i = 1; i <= n; i++){
		if(st[i][0] == 1){
			printf("%d ", ++ans);
			last = i;
			continue;
		}
		int l = last, r = i - 1, now = st[i][0], pos = i;
		while(true){
			while(l < r){
				int mid = (l + r + 1) >> 1;
				if(getgcd(mid, i) == now) r = mid - 1;
				else l = mid;
			}
			if(i - pos + 1 <= now && now <= i - l){
				ans++;
				last = i;
				break;
			}
			if(l == last) break;
			now = getgcd(l, i);
			pos = l;
			l = last, r--;
		}
		printf("%d ", ans);
	}
	return 0;
}