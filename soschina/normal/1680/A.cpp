#include <cstdio>
#include <iostream>
using namespace std;

int t, l1, r1, l2, r2;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        if(r1 >= l2 && l1 <= r2)
            printf("%d\n", max(l1, l2));
        else
            printf("%d\n", l1 + l2);
    }
    return 0;
}