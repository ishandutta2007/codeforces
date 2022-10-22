#include <bits/stdc++.h>

#define LL long long
#define ULL unsigned long long
#define pii pair<int,int>
using namespace std;
const int inf = 2147483647;
const int N = 200002;
const int mod = 104947357;
const int md = 100037579;
const int P1 = 131;
int P2 = 1331;
int P3 = rand() * rand() % 10000 + 1;

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

char s1[N], s2[N];
int f1[N], f2[N];

int main() {
	scanf("%s", s1 + 1);
	scanf("%s", s2 + 1);
	int u = strlen(s2 + 1);
	int len = strlen(s1 + 1);
	f1[0] = 0;
	for(int i = 1; i <= len; i++) {
		if(s1[i] == s2[f1[i - 1] + 1]) f1[i] = f1[i - 1] + 1;
		else f1[i] = f1[i - 1];
	} f2[len + 1] = u + 1;
	for(int i = len; i >= 1; i--) {
		if(s1[i] == s2[f2[i + 1] - 1]) f2[i] = f2[i + 1] - 1;
		else f2[i] = f2[i + 1];
	} int tp = 1, ans = 0;
	while(f2[tp] == 1) tp++;
	ans = _max(ans, tp - 2);
	tp = len;
	while(f1[tp] == u) tp--;
	ans = _max(ans, len - tp - 1);
	tp = 1;
	for(int i = 1; i <= len; i++) {
		while(tp <= i) tp++;
		while(tp <= len && f1[i] + 1 >= f2[tp]) tp++;
		tp--;
		ans = _max(ans, tp - i - 1);
	} put(ans), puts("");
	return 0;
}