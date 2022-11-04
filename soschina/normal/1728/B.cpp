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
            a[i] = i;
        reverse(a + 1, a + n - 1);
        if(n & 1)
            reverse(a + 1, a + 3);
        for (int i = 1; i <= n; i++)
            printf("%d ", a[i]);
        putchar('\n');
    }
	return 0;
}