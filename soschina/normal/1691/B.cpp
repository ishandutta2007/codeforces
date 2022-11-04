#include <cstdio>
using namespace std;
const int N = 1e5 + 1;

int t, n, a[N], p[N];

int main(){
	scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        int last = 1;
        for (int i = 2; i <= n; i++){
            if(a[i] != a[i - 1]){
                for (int j = last; j + 1 < i; j++)
                    p[j] = j + 1;
                p[i - 1] = last;
                last = i;
            }
        }
        for (int i = last; i < n; i++)
            p[i] = i + 1;
        p[n] = last;
        bool flag = true;
        for (int i = 1; i <= n; i++)
            if(p[i] == i)
                flag = false;
        if(!flag){
            puts("-1");
            continue;
        }
        for (int i = 1; i <= n; i++)
            printf("%d ", p[i]);
        putchar('\n');
    }
	return 0;
}