#include <cstdio>
using namespace std;
const int N = 101;

int t, n, k, a[N];

int main(){
	scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &k);
        int ans = 0;
        for (int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            if(i <= k && a[i] > k)
                ans++;
        }
        printf("%d\n", ans);
    }
	return 0;
}