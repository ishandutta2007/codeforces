#include <cstdio>
using namespace std;
const int N = 51;

int t;
char s[N];

int main(){
	scanf("%d", &t);
	while(t--){
		int cnt = 0;
		scanf("%s", s);
		for(char *c = s; *c; c++){
			if(*c == 'N') cnt++;
		}
		puts(cnt == 1 ? "NO" : "YES");
	}
	return 0;
}