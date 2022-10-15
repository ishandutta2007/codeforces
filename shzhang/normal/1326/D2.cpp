#include <cstdio>
#include <cstring>

using namespace std;

int pprefix(const char* start, int len)
{
    char* s = new char[len * 2 + 10];
    int* kmp = new int[len * 2 + 10];
    for (int i = 0; i < len; i++) s[i] = start[i];
    s[len] = 'A'; s[len + 1] = 'B';
    for (int i = 0; i < len; i++) s[len * 2 + 1 - i] = start[i];

    kmp[0] = 0;
    for (int i = 1; i < 2 * len + 2; i++) {
        int pre = i - 1;
        while (pre >= 0 && s[kmp[pre]] != s[i]) pre = kmp[pre] - 1;
        if (pre >= 0) {
            kmp[i] = kmp[pre] + 1;
        } else {
            kmp[i] = 0;
        }
    }

    //for (int i = 0; i < len; i++) printf("%d ", kmp[i]);

    int retv = kmp[len * 2 + 1];
    delete[] s;
    delete[] kmp;
    return retv;
}

char st[1000005];

void work(void)
{
    scanf("%s", st);
    int n = strlen(st);
    char* st2 = new char[n + 5];
    int x = 0; int y = n - 1;
    while (x < y && st[x] == st[y]) x++, y--;
    if (x >= y) {
        printf("%s\n", st); return;
    }
    for (int i = x; i <= y; i++) st2[x + y - i] = st[i];
    int pre_palin = pprefix(st + x, y - x + 1);
    int suf_palin = pprefix(st2 + x, y - x + 1);
    for (int i = 0; i < x; i++) printf("%c", st[i]);
    if (pre_palin > suf_palin) {
        for (int i = x; i < x + pre_palin; i++) printf("%c", st[i]);
    } else {
        for (int i = y - suf_palin + 1; i <= y; i++) printf("%c", st[i]);
    }
    for (int i = y + 1; i < n; i++) printf("%c", st[i]);
    printf("\n");
    delete[] st2;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}