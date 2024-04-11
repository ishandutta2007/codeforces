#include <cstdio>
#include <cstring>
using namespace std;
const int N = 200001;

int t, n, p;
char s[N];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%s", s);
		n = strlen(s);
		bool find = false;
		for(int i = n - 1; i > 0; i--) if(s[i] + s[i - 1] - '0' - '0' >= 10){
			find = true;
			p = i;
			break;
		}
		if(find){
			for(int i = 0; i < p - 1; i++)
				putchar(s[i]);
			int num = s[p - 1] + s[p] - '0' - '0';
			putchar(num / 10 + '0');
			putchar(num % 10 + '0');
			for(int i = p + 1; i < n; i++)
				putchar(s[i]);
			putchar('\n');
			continue;
		}
		putchar(s[0] + s[1] - '0');
		for(int i = 2; i < n; i++)
			putchar(s[i]);
		putchar('\n');
	}
	return 0;
}