#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int N = 1000;

int n;
int a[N];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= n; i++) {
        char ch = 'R', ch2 = 'L';
        if (i == n)
            ch = 'L', ch2 = 'R';
        while(a[i]--) {
            printf("P");
            printf("%c%c", ch, ch2);
        }
        if (i != n)
            printf("R");
    }
    printf("\n");
    return 0;
}