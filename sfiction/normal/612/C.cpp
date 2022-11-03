#include <cctype>
#include <cstdio>

const int MAXN = 1E6 + 10;

int top;
char que[MAXN];
int s[128];

int main(){
	s['('] = s['['] = s['{'] = s['<'] = 0;
	s[')'] = s[']'] = s['}'] = s['>'] = 1;
	char c;
	int cnt = 0;
	top = -1;
	while (isgraph(c = getchar()))
		if (s[c]){
			if (top < 0 || s[que[top]]){
				cnt = -MAXN;
				break;
			}
			else
				cnt += que[top] < c - 2 || c <= que[top];
			--top;
		}
		else
			que[++top] = c;
	if (top >= 0)
		cnt = -MAXN;
	if (cnt < 0)
		puts("Impossible");
	else
		printf("%d\n", cnt);
	return 0;
}