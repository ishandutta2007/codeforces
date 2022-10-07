#include <cstdio>

using namespace std;

char str[12345678];
char ans[12345678];

int main() {
    scanf("%s", str);
    bool prv = false;
    int len = 0;
    for(int i = 0; str[i]; ++i) {
        if (str[i] == '/') {
            if (prv) continue;
            else prv = true;
        } else {
            prv = false;
        }
        ans[len++] = str[i];
    }
    if (len > 1 && ans[len - 1] == '/') ans[len - 1] = 0;
    printf("%s\n", ans);
    return 0;
}