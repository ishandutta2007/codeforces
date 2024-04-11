#include <bits/stdc++.h>

#define LL long long
#define pii pair<int,int>
using namespace std;
const int inf = 2147483647;
const int N = 100001;

int _max(int x, int y) {return x > y ? x : y;}
int _min(int x, int y) {return x < y ? x : y;}
inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x * f;
}
void put(int x) {
	if(x < 0) putchar('-'), x = -x;
	if(x >= 10) put(x / 10);
	putchar(x % 10 + '0');
}

map<int, int> mp;
int a[N];

int main() {
	int n = read();
	for(int i = 1; i <= n; i++) a[i] = read(), mp[a[i]]++;
	sort(a + 1, a + n + 1);
	LL sum = a[1];
	for(int i = 2; i <= n; i++) sum += a[i] - (i - 1);
	int l = 1;
	int s = 0;
	for(int i = 2; i <= n; i++) {
		if(a[i] != a[i - 1]) {
			int r = i - 1;
			if(r - l + 1 >= 3) {
				puts("cslnb");
				return 0;
			} else if(r - l + 1 == 2) {
				s++;
				if(mp[a[l] - 1]) {
					puts("cslnb");
					return 0;
				}
			}
			l = i;
		}
	} if(n - l + 1 >= 3) {puts("cslnb"); return 0;
	} else if(n - l + 1 == 2) {
		s++;
		if(mp[a[n] - 1]) {
			puts("cslnb");
			return 0;
		}
	} if(s >= 2) {
		puts("cslnb");
		return 0;
	} else if(s == 1) {
		if(mp[0] == 2) {
			puts("cslnb");
			return 0;
		}
	}
	sum++;
	if(sum & 1) puts("cslnb");
	else puts("sjfnb");
	return 0;
}