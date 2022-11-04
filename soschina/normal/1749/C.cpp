#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 101;

int t, n, a[N];

int main(){
	scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        sort(a + 1, a + 1 + n);
        int k;
        for (k = (n - 1) / 2 + 1; k >= 0; k--){
            bool flag = true;
            for (int i = 1; i <= k; i++)
                if(a[2 * k - i] > k - i + 1)
                    flag = false;
            if(flag)
                break;
        }
        printf("%d\n", k);
    }
	return 0;
}