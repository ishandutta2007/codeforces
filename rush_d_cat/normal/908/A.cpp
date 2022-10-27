/*









*/


#include <iostream>
#include <cstring>
using namespace std;
char s[52];
int main() {
    scanf("%s", s+1);
    int n = strlen(s+1);
    int cnt = 0;
    for (int i = 1; i <= n; i ++) {
        if (s[i] <= '9' && s[i] >= '0') {
            if ((s[i]-'0') % 2) cnt ++;
        }
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'o' 
                || s[i] == 'i' || s[i] == 'u')
            cnt ++;
    }
    printf("%d\n", cnt);
}