#include <iostream>
#include <cmath>
using namespace std;
int t,d;

int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&d);
        if(d*d-4*d < 0) {
            printf("N\n"); continue;
        }
        double x1 = (1.0*d - sqrt(d*d - 4*d)) / 2.0;
        double x2 = (1.0*d + sqrt(d*d - 4*d)) / 2.0;
        printf("Y %.10f %.10f\n", x2,x1);
    }
}

/*
v 
*/