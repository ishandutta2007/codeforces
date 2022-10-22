#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int N, A, B;
int ans[10];
int chk[10] = {0, 4, 8, 15, 16, 23, 42};

int main(){
    printf("? 1 2\n");
    fflush(stdout);
    scanf("%d", &ans[2]);
    printf("? 1 3\n");
    fflush(stdout);
    scanf("%d", &ans[3]);
    printf("? 1 4\n");
    fflush(stdout);
    scanf("%d", &ans[4]);
    printf("? 1 5\n");
    fflush(stdout);
    scanf("%d", &ans[5]);

    for (int i=1; i<=6; i++){
        int a = ans[2] / chk[i];
        int b = ans[3] / chk[i];
        int c = ans[4] / chk[i];
        int d = ans[5] / chk[i];
        for (int j=1; j<=6; j++){
            if (a == chk[j]) a=0;
            if (b == chk[j]) b=0;
            if (c == chk[j]) c=0;
            if (d == chk[j]) d=0;
        }
        if (!a && !b && !c && !d) {
            ans[1] = chk[i];
            break;
        }
    }
    ans[2] /= ans[1];
    ans[3] /= ans[1];
    ans[4] /= ans[1];
    ans[5] /= ans[1];

    printf("! ");
    for (int i=1; i<=5; i++) {
        printf("%d ", ans[i]);
        for (int j=1; j<=6; j++) if (chk[j] == ans[i]) chk[j] = 0;
    }
    for (int i=1; i<=6; i++) if (chk[i]) printf("%d\n", chk[i]);
    fflush(stdout);
    return 0;
}