#include <cstdio>
using namespace std;

int t, n;

int main(){
	scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        printf("%d\n", (n - 6) / 3);
    }
	return 0;
}