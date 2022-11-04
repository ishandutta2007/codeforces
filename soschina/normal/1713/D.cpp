#include <cstdio>
using namespace std;

int t, n;

int solve(int l, int r){
    if(l == r)
        return l;
    int mid = (l + r) >> 1;
    int lmid = (l + mid) >> 1;
    int rmid = (mid + 1 + r) >> 1;
    int a = solve(l, lmid);
    int b = solve(lmid + 1, mid);
    int c = solve(mid + 1, rmid);
    int d = solve(rmid + 1, r);
    printf("? %d %d\n", a, c);
    fflush(stdout);
    int x;
    scanf("%d", &x);
    if(x == 1)
        c = d;
    else if(x == 2)
        a = b;
    else
        a = b, c = d;
    printf("? %d %d\n", a, c);
    fflush(stdout);
    scanf("%d", &x);
    if(x == 1)
        return a;
    else
        return c;
}

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        if(n & 1){
            int a = solve(1, 1 << (n - 1));
            int b = solve((1 << (n - 1)) + 1, 1 << n);
            printf("? %d %d\n", a, b);
            fflush(stdout);
            int x;
            scanf("%d", &x);
            if(x == 1)
                printf("! %d\n", a);
            else
                printf("! %d\n", b);
            fflush(stdout);
        }
        else{
            printf("! %d\n", solve(1, 1 << n));
            fflush(stdout);
        }
    }
    return 0;
}