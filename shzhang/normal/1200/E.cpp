#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char kmpstr[3000005];
int kmplen;
int kmp[3000005];

char curword[1000005];
char curstack[1000005];
int curnext = 0;

void work(void)
{
    for (int i = kmplen; i >= 1; i--) {
        kmpstr[i] = kmpstr[i-1];
    }
    kmp[1] = 0; //printf("0 ");
    for (int i = 2; i <= kmplen; i++) {
        int cur = i-1; kmp[i] = 0;
        while (cur) {
            if (kmpstr[kmp[cur]+1] == kmpstr[i]) {
                kmp[i] = kmp[cur]+1; break;
            } else {
                cur = kmp[cur];
            }
        }
        //printf("%d ", kmp[i]);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", curword);
        int wordlen = strlen(curword);
        int cur;
        for (cur = 0; curword[cur]; cur++) kmpstr[cur] = curword[cur];
        kmpstr[cur] = '?';
        kmpstr[cur+1] = '!';
        cur += 2;/* int a = curnext - 1; int copied = 0;
        while (a >= 0) {
            kmpstr[cur] = curstack[a]; a--; cur++; copied++; if (copied >= wordlen) break;
        }*/
        for (int j = max(curnext-wordlen, 0); j < curnext; j++) kmpstr[cur++] = curstack[j];
        kmpstr[cur] = '\0'; kmplen = cur;
        //printf("%s\n", kmpstr);
        work(); //printf("\n");
        for (int j = kmp[kmplen]; j < wordlen; j++) curstack[curnext++] = curword[j];
    }
    curstack[curnext] = '\0';
    printf("%s", curstack); return 0;
}