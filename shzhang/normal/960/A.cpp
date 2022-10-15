#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <cstdlib>

using namespace std;

char s[5005];

int main()
{
    scanf("%s", s);
    int acnt = 0, bcnt = 0, ccnt = 0;
    for (int i = 0; s[i]; i++) {
        if (i && s[i-1] > s[i]) {
            printf("NO"); return 0;
        }
        if (s[i] == 'a') {
            acnt++;
        } else if (s[i] == 'b') {
            bcnt++;
        } else {
            ccnt++;
        }
    }
    if (!acnt || !bcnt || (ccnt != acnt && ccnt != bcnt)) {
        printf("NO");
    } else {
        printf("YES");
    }
    return 0;
}