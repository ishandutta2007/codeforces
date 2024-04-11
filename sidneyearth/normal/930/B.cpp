#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
char s[maxn];
int head[maxn], nxt[maxn], cnt[maxn];
int main(){
	scanf("%s", &s);
	int n = strlen(s), m = 26;
	for(int i = 0; i < m; i++)
		head[i] = -1;
	for(int i = 0; i < n; i++){
		s[i] -= 'a';
		s[i + n] = s[i];
		nxt[i] = head[s[i]];
		head[s[i]] = i;
	}
	int ans = 0;
	for(int i = 0; i < m; i++){
		int mx = 0;
		for(int j = 1; j < n; j++){
			for(int k = 0; k < m; k++)
				cnt[k] = 0;
			for(int id = head[i]; id != -1; id = nxt[id])
				cnt[s[id + j]]++;
			int cur = 0;
			for(int k = 0; k < m; k++)
				cur += cnt[k] == 1;
			mx = max(cur, mx);
		}
		ans += mx;
	}
	printf("%.10lf\n", (double)ans / n);
	return 0;
}