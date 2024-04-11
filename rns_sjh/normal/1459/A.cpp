#include<bits/stdc++.h>
using namespace std;

#define N 1010

int t, n;
char r[N], b[N];

int main() {
    for(scanf("%d", &t); t --; ) {
        scanf("%d", &n);
        scanf("%s%s", r, b);
        int cnt = 0;
        for(int i = 0; i < n; i ++) if(r[i] != b[i]) cnt += (r[i] > b[i] ? 1 : -1);
        if(cnt > 0) puts("RED");
        else if(cnt == 0) puts("EQUAL");
        else puts("BLUE");
    }
}