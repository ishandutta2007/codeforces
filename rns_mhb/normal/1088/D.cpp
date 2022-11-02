#include<bits/stdc++.h>
using namespace std;

void in(int &x) {scanf("%d", &x); if(x==0) x = -1;}

int main() {
    int A = 0, B = 0, sgn = 0, res;
    for(int i = 29; i >= 0; i --) {
        int x = (1 << i), C = A, D = B;
        if(sgn == 0) {
            printf("? %d %d\n", C, D);
            fflush(stdout);
            in(sgn);
        }
        printf("? %d %d\n", C^x, D^x);
        fflush(stdout);
        in(res);
        if(res == sgn) {
            printf("? %d %d\n", C^x, D);
            fflush(stdout);
            in(res);
            if(res == -1) A ^= x, B ^= x;
        }
        else {
            if(res == 1) B ^= x;
            else A ^= x;
            sgn = 0;
        }
    }
    printf("! %d %d\n", A, B);
    fflush(stdout);
}