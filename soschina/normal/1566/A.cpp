#include <cstdio>
using namespace std;

int t, n, s;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &s);
		if(n & 1) printf("%d\n", s / (n - n / 2));
		else printf("%d\n", s / (n + 1 - n / 2));
	}
	return 0;
}