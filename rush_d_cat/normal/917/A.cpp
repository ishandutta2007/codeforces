#include <iostream>
#include <cstring>
using namespace std;
const int N = 200000+10;
char s[N];
int main() {
    scanf("%s", s+1);
    int n = strlen(s+1);
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        int mx = 0, mn = 0;
        for (int j = i; j <= n; j ++) {
            if (s[j] == '(')
                mx ++, mn ++;
            if (s[j] == ')')
                mx --, mn --;
            if (s[j] == '?') {
                mx ++, mn --;
            }
            if (mn < 0) mn += 2;
            if (mx < 0) break;

            if (mn == 0) ans ++;
        }
    }
    cout << ans << endl;
}