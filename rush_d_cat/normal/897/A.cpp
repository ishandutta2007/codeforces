#include <iostream>
using namespace std;
int n, m, l, r; char c1, c2;
char s[102];
int main() {
    cin >> n >> m;
    scanf("%s", s+1);
    for (int i = 1; i <= m; i ++) {
        cin >> l >> r >> c1 >> c2;
        for (int j=l;j<=r;j++) {
            if (s[j] == c1)
                s[j] = c2;
        }
    }
    printf("%s\n", s+1);
}