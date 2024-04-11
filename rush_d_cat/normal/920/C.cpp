#include <iostream>
#include <algorithm>
using namespace std;
const int N = 200000+10;
int n, a[N];
char s[N];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    scanf("%s", s+1);

    for (int i = 1; i < n; i ++) {

        if (s[i] == '1') {
            int j;
            for (j = i; j < n; j ++) {
                if (s[j] == '0') break;
            }
            j --;
            sort(a+i, a+2+j);
            i = j;
        }
    }
    bool ok = 1;
    for (int i = 1; i <= n; i ++) if (a[i] != i) ok = 0;
    printf("%s\n", ok?"YES":"NO");
}