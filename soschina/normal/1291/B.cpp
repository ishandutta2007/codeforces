#include <cstdio>
using namespace std;
const int N = 3e5;

int t, n, a[N], p;

int main(){
	scanf("%d", &t);
	while(t--){
		p = 0;
		scanf("%d", &n);
		for(int i = 0; i < n; i++){
			scanf("%d", a + i);
			if(p == i && a[i] >= i) p++;
		}
		for(int i = n - 1; ; i--){
			if(a[i] < n - i - 1){
				puts("No");
				break;
			}
			if(i < p){
				puts("Yes");
				break;
			}
		}
	}
	return 0;
}