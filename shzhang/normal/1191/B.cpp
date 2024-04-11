#include <cstdio>
#include <algorithm>

using namespace std;

int n[10];
char s[10];

char suits[] = {'m', 'p', 's'};

bool good(int cnt)
{
    for (int i = 1; i <= cnt; i++) {
        for (int j = i + 1; j <= cnt; j++) {
            for (int k = j + 1; k <= cnt; k++) {
                if (s[i] == s[j] && s[j] == s[k]) {
                    if (n[i] == n[j] && n[j] == n[k]) return true;
                    int a[3];
                    a[0] = n[i]; a[1] = n[j]; a[2] = n[k];
                    sort(a, a + 3);
                    if (a[1] - a[0] == 1 && a[2] - a[1] == 1) return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    char st[5];
    for (int i = 1; i <= 3; i++) {
        scanf("%s", st);
        n[i] = st[0] - '0';
        s[i] = st[1];
    }
    if (good(3)) {
        printf("0"); return 0;
    }
    for (n[4] = 1; n[4] <= 9; n[4]++) {
        int i;
        for (i = 0; i <= 2; i++) {
            s[4] = suits[i];
            if (good(4)) {
                printf("1"); return 0;
            }
        }
    }

    printf("2");
    return 0;
}