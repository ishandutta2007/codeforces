#include <cstdio>
#include <cctype>
#include <iostream>
using namespace std;
const int MAXN = 1e5 + 1;

void read(int &x){
	x = 0;
	int type = 1;
	char c = getchar();
	while(!isdigit(c) && c != '-') c = getchar();
	if(c == '-') type = -1, c = getchar();
	do{
		x = (x << 1) + (x << 3) + c - '0';
		c = getchar();
	}while(isdigit(c));
	x *= type;
}

int t, n, a[MAXN];
long long sum, now, ans;

int main(){
	read(t);
	while(t--){
		sum = 0;
		ans = -1e9;
		read(n);
		for(int i = 1; i <= n; i++){
			read(a[i]);
			sum += a[i];
		}
		now = 0;
		for(int i = 1; i < n; i++){
			now = (now > 0 ? now : 0) + a[i];
			ans = max(ans, now);
		}
		now = 0;
		for(int i = 2; i <= n; i++){
			now = (now > 0 ? now : 0) + a[i];
			ans = max(ans, now);
		}
		printf("%s\n", ans < sum ? "YES" : "NO");
	}
	return 0;
}