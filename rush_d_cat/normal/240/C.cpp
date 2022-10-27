#include <iostream>
using namespace std;
int n;
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d", &n);
    int i=0;
    for (i=0;i<19;i++) {
        if (n<=(1<<i)) break;
    }
    printf("%d\n", i);
    for (int bit=0;bit<i;bit++) {
        int cnt = 0;
        for (int j=1;j<=n;j++)
            if ((j>>bit)&1)
                cnt ++;
        printf("%d ", cnt);
        for (int j=1;j<=n;j++)
            if ((j>>bit)&1)
                printf("%d ", j);
        printf("\n");
    }
}

/*
001
010
011
100
*/