#include <iostream>
#include <cstring>
using namespace std;
const int N = 300000 + 10;

char s[N];

int main() {
    scanf("%s", s + 1);
    int l = 1, r = strlen(s + 1), n = r; 
    while (1) {
        int ll = l, rr = r;
        while (l <= n && s[l] == s[ll]) l ++;
        while (r >= 1 && s[r] == s[rr]) r --;
        if ( (l-ll) + (rr-r) <= 2 ) return !printf("0\n");
        if (s[ll] != s[rr]) return !printf("0\n");
        if (l > r && l - r <= 2) return !printf("0\n"); 
        if (l > r) {
            return !printf("%d\n", l - r);
        }
    }
}