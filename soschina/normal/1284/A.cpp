#include <cstdio>
using namespace std;
const int MAXN = 21, MAXL = 11;

int n, m, q, num;
char s[MAXN][MAXL], t[MAXN][MAXL];

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++)
		scanf("%s", s[i]);
	for(int i = 0; i < m; i++)
		scanf("%s", t[i]);
	scanf("%d", &q);
	while(q--){
		scanf("%d", &num);
		printf("%s%s\n", s[(num - 1) % n], t[(num - 1) % m]);
	}
	return 0;
}