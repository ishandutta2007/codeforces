#include <cstdio>
using namespace std;
const int N = 9;

int t, n, m;

int main(){
	scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        printf("%d %d\n", (1 + n) / 2, (1 + m) / 2);
    }
	return 0;
}