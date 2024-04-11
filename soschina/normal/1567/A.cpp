#include <cstdio>
#include <string>
#include <map>
using namespace std;

char c[256], s[101];
int t, n;

int main(){
	c['U'] = 'D';
	c['D'] = 'U';
	c['L'] = 'L';
	c['R'] = 'R';
	scanf("%d", &t);
	while(t--){
		scanf("%d%s", &n, s);
		for(char *i = s; *i; i++)
			putchar(c[*i]);
		putchar('\n');
	}
	return 0;
}