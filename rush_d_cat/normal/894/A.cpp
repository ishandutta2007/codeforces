#include <iostream>
#include <cstring>

using namespace std;

char s[102];

int main() {
    scanf("%s", s+1);
    int n = strlen(s+1);

    int cnt = 0;

    for (int i = 1; i <= n; i ++) {
        for (int j = i + 1; j <= n; j ++) {
            for (int k = j + 1; k <= n; k ++) {
                if (s[i]=='Q' && s[j]=='A' && s[k] == 'Q')
                    cnt ++;
            }
        }
    }

    printf("%d\n", cnt);

}