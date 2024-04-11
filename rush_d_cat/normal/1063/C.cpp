#include <iostream>
using namespace std;
int n, cnt = 0, flag = 0, ansx;
int query(int x,int y) {
    printf("%d %d\n", x, y); 
    fflush(stdout);
    char s[5]; scanf("%s",s);
    cnt ++;
    if(s[0]=='b') return 1;
    return 0;
}

int main() {
    scanf("%d",&n);
    int x = 0, y = 0; ansx = 10000000;
    int col = query(x,y);

    for(int i=1;i<n;i++) {
        x += 2;
        int tmp = query(x,y);
        if (tmp!=col) {
            ansx = x - 1;
            break;
        }
    }
    int rem = n - cnt;
    //printf("rem = %d\n", rem);
    if(rem == 0) {
        printf("%d %d %d %d\n", ansx, 0, ansx, 2); fflush(stdout);
        return 0;
    }
    int L = x - 2, R = x;
    int mid = (L+R)/2;

    int dt = 1<<28, h = dt, ansy=1;

    for(int i=1;i<=rem;i++) {
        if (query(R,h) == col) {
            dt>>=1, ansy=h-1, h-=dt;
        } else {
            dt>>=1, ansy=h+1, h+=dt;
        }
    }
    printf("%d %d %d %d\n", L+1, 0, R, ansy);
    fflush(stdout);
}