#include <cstdio>
using namespace std;
const int N = 52;

int t, n, i;
char s[N];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%s", &n, s + 1);
		for(i = 1; i < n; i++)
			if(s[i] != s[i + 1]){
				printf("%d %d\n", i, i + 1);
				break;
			}
		if(i == n) puts("-1 -1");
	}
	return 0;
}