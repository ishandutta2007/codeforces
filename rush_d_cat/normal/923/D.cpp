#include <iostream>
#include <cstring>
using namespace std;
const int N = 100000 + 10;
char s[N], t[N];
int Q;

int s1[N], s2[N];
int p1[N], p2[N];

int main() {
    scanf("%s %s", s+1, t+1);
    int sLen = strlen(s+1);
    int tLen = strlen(t+1);
    
    for (int i = 1; i <= sLen; i ++) {
        s1[i] = s1[i-1] + (s[i]=='B'||s[i]=='C');
        if (s[i]=='B'||s[i]=='C') {
            p1[i] = i;
        } else {
            p1[i] = p1[i-1];
        }
    }

    for (int i = 1; i <= tLen; i ++) {
        s2[i] = s2[i-1] + (t[i]=='B'||t[i]=='C');
        if (t[i]=='B'||t[i]=='C') {
            p2[i] = i;
        } else {
            p2[i] = p2[i-1];
        }
    }

    scanf("%d", &Q);
    while (Q --) {
 
        int x, y, l, r;
        scanf("%d %d %d %d", &x ,&y, &l, &r);
        int B1 = s1[y] - s1[x-1];
        int B2 = s2[r] - s2[l-1];
        int A1 = min(y - p1[y], y - x + 1);
        int A2 = min(r - p2[r], r - l + 1);

        bool ok = 1; 
        if (A1 < A2) {
            ok = 0;
        } else if ( (A1-A2)%3 ) {
            B1 += 2;
        } else {
            if (A1 != A2) {
                B1 += 2;
                if ( ( (B2-B1)%2 ==0 && B2-B1 >= 0 ) ) {
                    printf("1"); continue;
                }
                B1 -= 2;
            }
        }

        if ((B2-B1) < 0) 
            ok = 0;

        if (B2 > 0 && B1 == 0) 
            ok = 0;
        
        if ((B2-B1)%2)
            ok = 0;

        printf("%d", ok?1:0);
    }
    printf("\n");


}