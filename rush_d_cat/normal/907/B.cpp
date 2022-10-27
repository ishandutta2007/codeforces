#include <iostream>
using namespace std;
char str[4];
char mp[10][10];
int x, y;
int main() {
    for (int i = 1; i <= 9; i ++) {
        for (int j = 1; j <= 3; j ++) {
            scanf("%s", str+1);
            for (int k = 1; k <= 3; k ++) {
                mp[i][3*(j-1)+k] = str[k];
            }
        }
    }

    scanf("%d %d", &x, &y);
    int px = x % 3, py = y % 3; 
    if (!px) px = 3;
    if (!py) py = 3;
    //printf("%d %d\n", px, py);
    int cnt = 0;
    for (int i = 1; i <= 9; i ++) {
        for (int j = 1; j <= 9; j ++) {
            if ((i + 2) / 3 == px && (j + 2) / 3 == py && mp[i][j] == '.') {
                cnt ++; mp[i][j] = '!';
            }
        }
    }

    if (cnt == 0) {
        for (int i = 1; i <= 9; i ++) {
            for (int j = 1; j <= 9; j ++) if (mp[i][j] == '.') {
                mp[i][j] = '!';
            }
        }
    }


    for (int i = 1; i <= 9; i ++) {
        for (int j = 1; j <= 9; j ++) {
            printf("%c", mp[i][j]);
            if (j%3==0) printf(" ");
        }
        printf("\n");
        if (i%3==0) printf("\n");
    }
}