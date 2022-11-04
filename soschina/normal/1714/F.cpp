#include <cstdio>
using namespace std;

int t, n, d12, d23, d31;

//(a+b)=d12, (b+c)=d23, (a+c)=d31

int main(){
	scanf("%d", &t);
    while(t--){
        scanf("%d%d%d%d", &n, &d12, &d23, &d31);
        int sum = (d12 + d23 + d31) / 2;
        int a = sum - d23;
        int b = sum - d31;
        int c = sum - d12;
        if(((d12 + d23 + d31) & 1) || a < 0 || b < 0 || c < 0 || !a + !b + !c > 1 || sum + 1 > n){
            puts("NO");
            continue;
        }
        puts("YES");
        int id = 4;
        int root = (!a || !b || !c) ? ((a ? 0 : 1) | (b ? 0 : 2) | (c ? 0 : 3)) : id++;
        if(a){
            int last = root;
            for (int i = 1; i < a; i++){
                printf("%d %d\n", last, id);
                last = id++;
            }
            printf("%d %d\n", last, 1);
        }
        if(b){
            int last = root;
            for (int i = 1; i < b; i++){
                printf("%d %d\n", last, id);
                last = id++;
            }
            printf("%d %d\n", last, 2);
        }
        if(c){
            int last = root;
            for (int i = 1; i < c; i++){
                printf("%d %d\n", last, id);
                last = id++;
            }
            printf("%d %d\n", last, 3);
        }
        int last = root;
        while(id <= n){
            printf("%d %d\n", last, id);
            last = id++;
        }
    }
	return 0;
}