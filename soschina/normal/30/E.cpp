#include <cstdio>
#include <cctype>
#include <queue>
using namespace std;
const int MAXN = 1e5 + 2;

inline int min(const int &a, const int &b){
	return a < b ? a : b;
}

int n, len[MAXN], pow[MAXN] = {1}, lh[MAXN], rh[MAXN], elen[MAXN], tp[MAXN], tl, ans, ansi;
queue<int> q;
char s[MAXN] = {'S'};

int main(){
	do s[++n] = getchar(); while(isalpha(s[n]));
	n--;
	
	for(int i = 1; i <= n; i++){
		pow[i] = pow[i - 1] * 29;
		lh[i] = lh[i - 1] * 29 + s[i];
	}
	for(int i = n; i; i--)
		rh[i] = rh[i + 1] * 29 + s[i];
	
	for(int i = 1; i <= n; i++){
		if(s[i] == s[n]) q.push(i);
		#define f q.front()
		while(!q.empty() && n - i + f > i && lh[i] - lh[f - 1] * pow[i - f + 1] != rh[n - i + f]) q.pop();
		if(q.empty() || i - f + 1 < elen[i - 1]){
			elen[i] = elen[i - 1];
			tp[i] = tp[i - 1];
		}else{
			elen[i] = i - f + 1;
			tp[i] = i;
		}
	}
	
	int r = 1, p = 0;
	for(int i = 1; i <= n; i++){
		len[i] = i < r ? min(len[(p << 1) - i], r - i) : 1;
		while(s[i - len[i]] == s[i + len[i]]) len[i]++;
		if(i + len[i] > r){
			r = i + len[i];
			p = i;
		}
		
		tl = min(elen[i - len[i]], n - i - len[i] + 1);
		if(len[i] + tl > ans){
			ans = len[i] + tl;
			ansi = i;
		}
	}
	tl = min(elen[ansi - len[ansi]], n - ansi - len[ansi] + 1);
	if(tl) printf("3\n%d %d\n%d %d\n%d %d", tp[ansi - len[ansi]] - elen[ansi - len[ansi]] + 1, tl, ansi - len[ansi] + 1, (len[ansi] << 1) - 1, n - tl + 1, tl);
	else printf("1\n%d %d", ansi - len[ansi] + 1, (len[ansi] << 1) - 1);
	return 0;
}