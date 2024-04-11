#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int N = 2e5 + 1;

int t, ans, cnt[10], len, cnti, cntj;
char s[N], last;

int main(){
	scanf("%d", &t);
	while(t--){
		memset(cnt, 0, sizeof(cnt));
		ans = 0x7fffffff;
		len = 0;
		scanf("%s", s);
		for(char *c = s; *c; c++){
			*c -= '0';
			len++, cnt[*c]++;
		}
		for(int i = 0; i < 10; i++)
			ans = min(ans, len - cnt[i]);
		for(int i = 1; i < 10; i++)
			for(int j = 0; j < i; j++){
				last = 10, cnti = cntj = 0;
				for(int p = 0; p < len; p++)
					if((i == s[p] || j == s[p]) && s[p] != last){
						last = s[p];
						if(s[p] == i) cnti++;
						else cntj++;
					}
				ans = min(ans, len - 2 * min(cnti, cntj));
			}
		printf("%d\n", ans);
	}
	return 0;
}