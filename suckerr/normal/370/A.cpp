#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <set>

using namespace std;

int r1, r2, c1, c2;

int main() {
    scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
    if (r1 == r2 && c1 == c2) {
        printf("0 0 0\n");
    } else {
        if (r1 == r2 || c1 == c2) {
            printf("1 ");
        } else {
            printf("2 ");
        }
        
        if (abs(r1 - r2) == abs(c1 - c2)) {
            printf("1 ");
        } else if ((r1 + c1) % 2 == (r2 + c2) % 2) {
            printf("2 ");
        } else {
            printf("0 ");
        }
        
        printf("%d\n", max(abs(r1 - r2), abs(c1 - c2)));
    }
    return 0;
}