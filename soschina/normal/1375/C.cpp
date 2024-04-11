#include <cstdio>
using namespace std;

int t, n, l, r;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &l);
		while(--n) scanf("%d", &r);
		puts(l < r ? "YES" : "NO");
	}
	return 0;
}