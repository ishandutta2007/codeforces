#include <cstdio>
#include <vector>
using namespace std;

int a, b, c, ans;
int fac[1000010];

int main(){
    for(int i = 1; i <= 1000000; i++){
	for(int j = i; j <= 1000000; j += i) fac[j]++;
    }
    scanf("%d %d %d", &a, &b, &c);
    for(int i = 1; i <= a; i++){
	for(int j = 1; j <= b; j++){
	    for(int k = 1; k <= c; k++){
		ans += fac[i * j * k];
	    }
	}
    }
    printf("%d\n", ans);
    return 0;
}