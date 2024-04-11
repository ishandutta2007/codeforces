#include <cstdio>
using namespace std;

int t, n;

int main(){
	scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        if(n & 1){
            while(n--)
                printf("1 ");
        }
        else{
            for (int i = 1; i < n; i++)
                printf("%d ", n | 1);
            printf("1 ");
        }
        putchar('\n');
    }
	return 0;
}