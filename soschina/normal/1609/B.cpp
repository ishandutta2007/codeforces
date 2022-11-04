#include <cstdio>
using namespace std;
const int N = 1e5 + 1;

int n, q, p, ans;
char c, s[N];

bool cmp(int i){
	return i >= 0 && i <= n - 3 && s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c';
}

int main(){
	scanf("%d%d%s", &n, &q, s);
	for(int i = 0; i <= n - 3; i++)
		if(cmp(i)) ans++;
	while(q--){
		scanf("%d %c", &p, &c);
		p--;
		if(cmp(p - s[p] + 'a')) ans--;
		s[p] = c;
		if(cmp(p - s[p] + 'a')) ans++;
		printf("%d\n", ans);
	}
	return 0;
}