#include <bits/stdc++.h>
using namespace std;

map <string, int> mp;

char s[111];

int main() {
    int n;
    scanf("%d", &n);
    while (n --) {
        scanf("%s", s);
        int &k = mp[s];
        if (!k) puts("OK");
        else printf("%s%d\n", s, k);
        k ++;
    }

    return 0;
}