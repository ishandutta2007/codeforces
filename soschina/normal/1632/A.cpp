#include <cstdio>
using namespace std;
const int N = 101;

int t, n, cnt[2];
char s[N];

int main(){
	scanf("%d", &t);
	while(t--){
		cnt[0] = cnt[1] = 0;
		scanf("%d%s", &n, s);
		if(n == 1){
			puts("YES");
			continue;
		}
		if(n == 2){
			puts(s[0] != s[1] ? "YES" : "NO");
			continue;
		}
		puts("NO");
	}
	return 0;
}