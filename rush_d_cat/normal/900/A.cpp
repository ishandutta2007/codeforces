#include <iostream>

using namespace std;
int n, x, y, cnt = 0;
int main() {
    scanf("%d", &n);
    for (int i=1;i<=n;i++) {
        scanf("%d %d", &x, &y);
        if (x < 0) cnt ++;
    }
    printf("%s\n", (cnt<=1)||(cnt==n-1)||(cnt==n)?"Yes":"No");
}