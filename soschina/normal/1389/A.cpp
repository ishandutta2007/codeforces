#include <cstdio>
using namespace std;

int t, l, r;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &l, &r);
		if(r < 2 * l) puts("-1 -1");
		else printf("%d %d\n", l, l * 2);
	}
	return 0;
}