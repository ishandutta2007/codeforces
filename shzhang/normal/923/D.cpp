#include <cstdio>
#include <algorithm>
//
using namespace std;

char S[100005], T[100005];
int q;
int Ssum[100005], Tsum[100005];
int Ssuffix[100005], Tsuffix[100005];

int main()
{
    scanf("%s", S + 1);
    scanf("%s", T + 1);
    for (int i = 1; S[i]; i++) {
        Ssum[i] = Ssum[i-1];
        if (S[i] != 'A') {
            Ssum[i]++; Ssuffix[i] = 0;
        } else {
            Ssuffix[i] = Ssuffix[i-1] + 1;
        }
    }
    for (int i = 1; T[i]; i++) {
        Tsum[i] = Tsum[i-1];
        if (T[i] != 'A') {
            Tsum[i]++; Tsuffix[i] = 0;
        } else {
            Tsuffix[i] = Tsuffix[i-1] + 1;
        }
    }
    //for (int i = 1; T[i]; i++) printf("%d ", Tsum[i]);
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        int l1, r1, l2, r2, a, b, x, y;
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        a = Ssuffix[r1]; a = min(a, r1-l1+1);
        b = Tsuffix[r2]; b = min(b, r2-l2+1);
        x = Ssum[r1] - Ssum[l1-1];
        y = Tsum[r2] - Tsum[l2-1];
        //printf("%d %d %d %d\n", a, b, x, y);
        if (a < b) {
            printf("0");
        } else {
            if (a == b && x == 0 && y != 0) {
                printf("0"); continue;
            }
            if ((a-b) % 3 != 0) x += 2;
            printf("%d", y >= x && (y - x) % 2 == 0 ? 1 : 0);
        }
    }
    return 0;
}