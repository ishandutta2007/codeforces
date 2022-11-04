#include <cstdio>
using namespace std;
const int N = 2e4 + 2;

int t, n;
char s[N];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%s", &n, s + 1);
		bool flag = true;
		for(int i = 1; flag && i <= n; i++) if(s[i] == '0'){
			flag = false;
			if(i <= n / 2) printf("%d %d %d %d\n", i, n, i + 1, n);
			else printf("%d %d %d %d\n", 1, i, 1, i - 1);
		}
		if(flag) printf("%d %d %d %d\n", 1, n / 2 * 2, 1, n / 2);
	}
	return 0;
}