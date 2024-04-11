#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

char R, S;

int main(){
    char r, s;
    scanf(" %c %c", &R, &S);
    for (int i=1; i<=5; i++){
        scanf(" %c %c", &r, &s);
        if (R == r || S == s) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}