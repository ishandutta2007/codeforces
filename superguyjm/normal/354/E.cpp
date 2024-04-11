#include <bits/stdc++.h>

#define LL long long
#define pii pair<int,int>
using namespace std;
const int inf = 2147483647;

int _max(int x, int y) {return x > y ? x : y;}
int _min(int x, int y) {return x < y ? x : y;}
inline LL read() {
    LL x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x * f;
}
void put(LL x) {
	if(x < 0) putchar('-'), x = -x;
	if(x >= 10) put(x / 10);
	putchar(x % 10 + '0');
}

struct node {int x, c;} last[20][10];
int sta[1000], tp;
vector<int> q[45];
int len, qq[20];
int f[20][10];
LL ll, pp[7];

void dfs(int k, int sum) {
	if(k == 7) {
		sta[++tp] = sum;
		q[sum].clear();
		for(int i = 1; i <= ll; i++) q[sum].push_back(pp[i]);
		return ;
	} pp[++ll] = 7, dfs(k + 1, sum + 7);
	pp[ll] = 4, dfs(k + 1, sum + 4);
	pp[ll] = 0, dfs(k + 1, sum), --ll;
}

int main() {
	dfs(1, 0);
	sort(sta + 1, sta + tp + 1);
	tp = unique(sta + 1, sta + tp + 1) - (sta + 1);
	int T = read();
	while(T--) {
		LL x = read();
		len = 0; while(x) qq[++len] = x % 10, x /= 10;
		memset(f, 0, sizeof(f));
		f[0][0] = 1;
		for(int i = 1; i <= len; i++) {
			for(int j = 0; j <= 9; j++) if(f[i - 1][j]){
				for(int k = 1; k <= tp; k++) if((sta[k] + j) % 10 == qq[i]){
					f[i][(sta[k] + j) / 10] = 1;
					last[i][(sta[k] + j) / 10] = node{k, j};
				}
			}
		} if(!f[len][0]) puts("-1");
		else {
			int o = 0;
			for(int i = len; i >= 1; i--) {
				qq[i] = last[i][o].x;
				o = last[i][o].c;
			} memset(pp, 0, sizeof(pp));
			for(int i = len; i >= 1; i--) {
				for(int j = 1; j <= 6; j++) pp[j] = pp[j] * 10 + q[sta[qq[i]]][j - 1];
			} for(int i = 1; i <= 6; i++) put(pp[i]), putchar(' ');
			puts("");
		}
	} return 0;
}