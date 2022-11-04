#include <cstdio>
using namespace std;
const int N = 1e5 + 1;

int t, n, s[N], p, q[N], l;
char str[N];

int main(){
	scanf("%d", &t);
	while(t--){
		l = p = 0;
		scanf("%d%s", &n, str);
		str[n] = '0';
		for(int i = 1; i <= n; i++)
			if(str[i] != str[i - 1]) q[++l] = i;
		scanf("%s", str);
		str[n] = '0';
		for(int i = 1; i <= n; i++)
			if(str[i] != str[i - 1]) s[p++] = i;
		printf("%d", p + l);
		for(int i = 1; i <= l; i++)
			printf(" %d", q[i]);
		while(~--p) printf(" %d", s[p]);
		putchar('\n');
	}
	return 0;
}