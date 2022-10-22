#include <bits/stdc++.h>
using namespace std;

int N, M, L, H;
char s[202020], t[202020];

int main() {
    scanf("%d %d", &N, &M);
    scanf("%s", s);
    scanf("%s", t);
    bool tf = false;
    for (int i=0; i<N; i++) if (s[i] == '*') tf = true;
    if (tf){
        int l=0, r=M-1;
        for (int i=0; s[i] != '*'; i++, l++) if (s[i] != t[l]){
            puts("NO");
            return 0;
        }
        l--;
        for (int i=N-1; s[i] != '*'; i--, r--) if (s[i] != t[r]){
            puts("NO");
            return 0;
        }
        r++;
        if (l < r) puts("YES");
        else puts("NO");
    }
    else{
        if (N != M) {
            puts("NO");
            return 0;
        }
        for (int i=0; i<N; i++) if (s[i] != t[i]){
            puts("NO");
            return 0;
        }
        puts("YES");
    }
    return 0;
}