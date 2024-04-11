#include <cstdio>
using namespace std;

int t, n;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		if(n % 7 == 0) printf("%d\n", n);
		else{
			for(int i = 0; i <= 9; i++)
				if((n / 10 * 10 + i) % 7 == 0){
					printf("%d\n", n / 10 * 10 + i);
					break;
				}
		}
	}
	return 0;
}