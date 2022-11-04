#include <cstdio>
using namespace std;
const int N = 101;

int t, n, a[N];

int main(){
	scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        scanf("%d", &a[1]);
        int ans = 0;
        for (int i = 2; i <= n; i++){
            scanf("%d", &a[i]);
            ans += (a[i] - 1) / (a[1] * 2 - 1);
        }
        printf("%d\n", ans);
    }
	return 0;
}