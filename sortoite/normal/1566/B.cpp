#include <bits/stdc++.h>

using namespace std;

const int NN = 1e5 + 10;
char s[NN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    int T; cin >> T;
    while(T --) {
        scanf("%s", s);
        int a = 0, b = 0;
        for(int i = 0; s[i]; i ++) {
            if(i && s[i] == s[i - 1]) continue;
            if(s[i] == '0') a ++;
            else b ++;
        }
        if(!a) puts("0");
        else if(!b) puts("1");
        else printf("%d\n", min(2, a));
    }
    return 0;
}