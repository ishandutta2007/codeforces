#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

const int N = 400000 + 10;
const int B = 131;

int n; 
char s[N], t[N];
bool solve(int l, int r, int l2, int r2) {
    bool gg = 0;
    for (int i = l; i < r; i ++) {
        if (s[i] != t[i - l + l2]) gg = 1;
    } 
    if (! gg) return 1;
    if ((r - l) % 2 == 1) return 0;
    
    int m1 = (l + r) >> 1;
    int m2 = (l2 + r2) >> 1;
    if (solve(l, m1, m2, r2) && solve(m1, r, l2, m2)) return 1;
    if (solve(l, m1, l2, m2) && solve(m1, r, m2, r2)) return 1;
    return 0;
}
int main() {
    scanf("%s%s", s, t);
    n = strlen(s);
    printf("%s\n", solve(0,n,0,n) ? "YES" : "NO");
}