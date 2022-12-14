//B
#include <stdio.h>
#include <string.h>

const int day[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int dd, mm, yy;
int b[4];

bool chk(int d, int m, int y){
    if(y < 1 || y > 99) return 0;
    if(m > 12 || m < 1) return 0;
    if(m == 2){
        if(y % 4 == 0) {
            if(d < 30 && d > 0) return 1;
            return 0;
        }
        if(d < 29 && d > 0) return 1;
        return 0;
    }
    if(d <= day[m] && d > 0) return 1;
    return 0;
}

bool ok(int dd, int mm, int yy, int bd, int bm, int by){
    if(!chk(bd, bm, by)) return 0;

    if(yy - by > 18) return 1;
    if(yy - by < 18) return 0;

    if(mm > bm) return 1;
    if(mm < bm) return 0;

    if(dd >= bd) return 1;
    return 0;
}

int main(){
    //freopen("a.in", "r", stdin);
    char t1, t2;
    scanf("%d%c%d%c%d", &dd, &t1, &mm, &t2, &yy);
    scanf("%d%c%d%c%d", &b[0], &t2, &b[1], &t2, &b[2]);

    for(int i = 0; i < 3; i ++){
        for(int j = 0; j < 3; j ++) if(j != i) {
            int k = 3 - i - j;
            if(ok(dd, mm, yy, b[i], b[j], b[k])) {puts("YES"); return 0;}
        }
    }

    puts("NO");
}