#include <cstdio>
using namespace std;
const int N = 101;

int t, n, ans;
char s[N];

int main(){
	scanf("%d", &t);
	while(t--){
		ans = 0;
		scanf("%d%s", &n, s);
		for(int i = 0; i + 1 < n; i++)
			if(s[i] > '0') ans += s[i] - '0' + 1;
		ans += s[n - 1] - '0';
		printf("%d\n", ans);
	}
	return 0;
}