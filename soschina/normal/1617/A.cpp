#include <cstdio>
#include <cstring>
using namespace std;
const int N = 102;
const char a[4] = "abc", b[4] = "acb";

int T, cnt[256];
char s[N], t[4];

int main(){
	scanf("%d", &T);
	while(T--){
		memset(cnt, 0, sizeof(cnt));
		scanf("%s%s", s, t);
		for(char *c = s; *c; c++)
			cnt[*c]++;
		if(t[0] == 'a' && t[1] == 'b' && t[2] == 'c' && cnt['a'] && cnt['b'] && cnt['c']){
			while(cnt['a']--) putchar('a');
			while(cnt['c']--) putchar('c');
			while(cnt['b']--) putchar('b');
			for(int i = 'c'; i <= 'z'; i++)
				for(int j = 0; j < cnt[i]; j++)
					putchar(i);
		}else{
			for(int i = 'a'; i <= 'z'; i++)
				for(int j = 0; j < cnt[i]; j++)
					putchar(i);
		}
		putchar('\n');
	}
}