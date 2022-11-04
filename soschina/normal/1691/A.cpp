#include <cstdio>
using namespace std;

int t, n, a;

int main(){
	scanf("%d", &t);
    while(t--){
        int ans = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++){
            scanf("%d", &a);
            if(a & 1)
                ans++;
        }
        if(n - ans < ans)
            ans = n - ans;
        printf("%d\n", ans);
    }
	return 0;
}