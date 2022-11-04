#include <cstdio>
using namespace std;
const int N = 2e5 + 2;

int t, n, p;
char s[N];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%s", &n, s + 1);
		s[n] = '>', p = 0;
		for(int i = 1; i <= n; i++) if(s[i] == '>'){
			for(int j = n - i + 1; j <= n - p; j++) printf("%d ", j);
			p = i;
		}
		putchar('\n');
		s[n] = '<', p = 0;
		for(int i = 1; i <= n; i++) if(s[i] == '<'){
			for(int j = i; j > p; j--) printf("%d ", j);
			p = i;
		}
		putchar('\n');
	}
	return 0;
}