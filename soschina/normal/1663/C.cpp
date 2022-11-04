#include <cstdio>
using namespace std;

int n, a, ans;

int main(){
	scanf("%d", &n);
	while(n--){
		scanf("%d", &a);
		ans += a;
	}
	printf("%d", ans);
	return 0;
}