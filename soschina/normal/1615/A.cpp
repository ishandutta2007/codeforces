#include <cstdio>
using namespace std;

int t, n, a, s;

int main(){
	scanf("%d", &t);
	while(t--){
		s = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++){
			scanf("%d", &a);
			s += a;
		}
		if(s % n == 0) puts("0");
		else puts("1");
	}
	return 0;
}