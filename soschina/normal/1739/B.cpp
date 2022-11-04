#include <cstdio>
using namespace std;
const int N = 101;

int t, n, d[N], a[N];

int main(){
	scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        bool flag = true;
        for (int i = 1; i <= n; i++){
            scanf("%d", &d[i]);
            if(d[i] && a[i - 1] - d[i] >= 0)
                flag = false;
            a[i] = a[i - 1] + d[i];
        }
        if(!flag)
            puts("-1");
        else{
            for (int i = 1; i <= n; i++)
                printf("%d ", a[i]);
            putchar('\n');
        }
    }
	return 0;
}