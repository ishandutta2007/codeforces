#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1e5 + 1;

int q, n, last[26], next[N][26], ans;
char s[N], t[N];

int main(){
	scanf("%d", &q);
	while(q--){
		ans = 0;
		scanf("%s%s", s, t);
		n = strlen(s);
		for(int i = 0; i < 26; i++)
			next[n][i] = last[i] = n + 1;
		for(int i = n - 1; ~i; i--){
			last[s[i] - 'a'] = i + 1;
			for(int j = 0; j < 26; j++)
				next[i][j] = last[j];
		}
		char *c = t;
		do{
			ans++;
			if(next[0][*c - 'a'] == n + 1){
				ans = -1;
				break;
			}
			int i = 0;
			do i = next[i][*c - 'a'], c++; while(*c && next[i][*c - 'a'] <= n);
		}while(*c);
		printf("%d\n", ans);
	}
	return 0;
}