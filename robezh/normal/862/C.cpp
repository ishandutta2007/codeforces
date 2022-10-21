#include<cstdio>
#include<iostream>
using namespace std;

int main() {
    int n,x;
    int start = 100020;
    scanf("%d %d", &n, &x);
    int tmpn = n;

    if(x != 0) {
        printf("YES\n");
        while(n > 4) {
            printf("%d %d %d %d ", start, start + 1, start + 2, start + 3);
            start += 4;
            n -= 4;
        }
        if(n == 1) {
            printf("%d", x);
        } else if(n == 2) {
            printf("%d %d", x + 131072, 131072);
        } else if(n == 3) {
            printf("%d %d %d", 786432 + x, 524288, 262144);
        } else {
            printf("%d %d %d %d", 262148, 393223, 524291, 655360 + x);
        }
    }
	else{
        if(n == 2) {
        	printf("NO\n");
		}
        else {
            printf("YES\n");
            while(n > 6) {
                printf("%d %d %d %d ", start, start + 1, start + 2, start + 3);
                start += 4;
                n -= 4;
            }
            if(n == 6){
            	printf("%d %d %d %d %d %d", 2, 3, 1, 5, 15, 10);
			}
			else if(n == 5){
				printf("%d %d %d %d %d", 1, 14, 13, 6, 4);
			}
			else if(n == 4){
				printf("%d %d %d %d", 2, 3, 4, 5);
			}
			else if(n == 3){
				printf("%d %d %d", 1, 2, 3);
			}
			else{
				printf("%d", 0);
			}
			
        }

    }

}