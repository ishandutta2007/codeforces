#include <cstdio>
using namespace std;
const int N = 1e5 + 2;

int t, n;
char s[2][N];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		scanf("%s%s", s[0] + 1, s[1] + 1);
		int last = -1, ans = 0;
		for(int i = 1; i <= n; i++){
			if(s[0][i] != s[1][i]){
				if(last == '0') ans++;
				ans += 2;
				last = -1;
			}else if(last == -1){
				last = s[0][i];
			}else if(last != s[0][i]){
				ans += 2;
				last = -1;
			}else if(last == '0') ans++;
		}
		if(last == '0') ans++;
		printf("%d\n", ans);
	}
	return 0;
}