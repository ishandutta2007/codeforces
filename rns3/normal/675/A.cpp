#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    scanf("%d %d %d", &a,&b, &c);
    if(c == 0) {
        if(a == b) return puts("YES");
        return puts("NO");
    }
    if((b-a)%c==0 && (b - a) / c >= 0) return puts("YES");
    puts("NO");
    return 0;
}