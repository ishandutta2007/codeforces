#include <cstdio>
#include <cmath>
using namespace std;

int t, n;

int main(){
	scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        n = (n + 1) / 2;
        int m = ceil(sqrt(n / 3.0));
        int ans = m * 3;
        long long num = 3ll * m * m;
        if(num - 2 * m >= n){
            num -= 2 * m;
            ans--;
            if(num - 2 * m + 1 >= n)
                ans--;
        }
        printf("%d\n", ans);
    }
	return 0;
}