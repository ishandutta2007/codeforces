#include<bits/stdc++.h>
using namespace std;

#define N 555

int a[N], b[N];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    printf("?");
    for(int i = 1; i <= k; i ++) printf(" %d", i);
    puts("");
    fflush(stdout);
    int mp, mv;
    scanf("%d%d", &mp, &mv);
    printf("?");
    for(int i = 1; i <= k; i ++) if(i != mp) printf(" %d", i);
    printf(" %d", k+1);
    puts("");
    fflush(stdout);
    int cp, cv;
    scanf("%d%d", &cp, &cv);
    if(cv > mv) {
        b[k+1] = 1;
        b[cp] = 1;
    }
    else {
        b[k+1] = -1;
        b[cp] = -1;
    }
    for(int i = 1; i <= k; i ++) if(i != mp && b[i] == 0) {
        printf("?");
        for(int j = 1; j <= k+1; j ++) if(j != i) printf(" %d", j);
        puts("");
        fflush(stdout);
        scanf("%d%d", &cp, &cv);
        if(mv == cv) b[i] = b[k+1];
        else b[i] = -b[k+1];
    }
    int m = 1;
    for(int i = 1; i <= k; i ++) if(b[i] == -1) m ++;
    printf("!");
    printf(" %d\n", m);
    fflush(stdout);
}