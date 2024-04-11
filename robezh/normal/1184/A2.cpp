#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;

int n;
char s[maxn];
int wow[maxn], rec[maxn];

int gcd(int x, int y) {
	if(y==0) return x;
	return gcd(y,x%y);
}

int main() {
	scanf("%d %s",&n,s);

	int ans = 0;
	
	//case 0
	int sum = 0;
	for(int i=0;i<n;i++) sum += s[i]-'0';
	if(sum == 0) ans++;

	for(int x=1;x<n;x++) {
		if(n%x == 0) {
			int good = 1;
			for(int i=0;i<n;i++) wow[i] = 0;
			for(int i=0;i<n;i++) wow[i%x] ^= s[i]-'0';
			for(int i=0;i<n;i++) if(wow[i%x]) good = 0;
			rec[x] = good;
		}
	}

	for(int x=1;x<n;x++) {
		ans += rec[gcd(n, x)];
	}

	printf("%d",ans);
}