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

char ss[N];
int s1[N], s2[N];

int main() {
	int n = read(), k = read();
	scanf("%s", ss + 1);
	for(int i = 1; i <= n; i++) s1[i] = s1[i - 1] + (ss[i] == '0'), s2[i] = s2[i - 1] + (ss[i] == '1');
	bool hh = 0;
	for(int i = 1; i <= n - k + 1; i++) {
		if(s1[i - 1] == 0 && s1[n] - s1[i + k - 1] == 0) {
			puts("tokitsukaze");
			return 0;
		} else if(s2[i - 1] == 0 && s2[n] - s2[i + k - 1] == 0) {
			puts("tokitsukaze");
			return 0;
		}
	} for(int i = 1; i <= n - k + 1; i++) {
		int ll = i + k - 1;
		bool bk = 0;
		if((s1[i - 1] <= k && (i - 1 <= k || s1[i - 1] == s1[k]) && s1[n] - s1[i + k - 1] == 0) || (s1[i - 1] == 0 && s1[n] - s1[ll] <= k && (n - ll <= k || s1[n - k] == s1[ll])));
		else bk = 1;
		if((s2[i - 1] <= k && (i - 1 <= k || s2[i - 1] == s2[k]) && s2[n] - s2[i + k - 1] == 0) || (s2[i - 1] == 0 && s2[n] - s2[ll] <= k && (n - ll <= k || s2[n - k] == s2[ll])));
		else bk = 1;
		if(bk) hh = 1;
	} if(!hh) puts("quailty");
	else puts("once again");
	return 0;
}