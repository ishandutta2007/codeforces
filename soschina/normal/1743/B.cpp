#include <cstdio>
using namespace std;

int t, n;

int main(){
	scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        printf("1 %d ", n);
        for (int i = 2; i < n; i++)
            printf("%d ", i);
        putchar('\n');
    }
	return 0;
}