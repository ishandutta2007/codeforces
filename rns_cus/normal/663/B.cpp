#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll, int> mp;
#define N 1100
char s[N];
int a[N], B[N];
int main() {
    //freopen("1.in", "r", stdin);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) {
        a[i] = 0;
        scanf("%s", s);
        int len = strlen(s);
        for(int j = 0; j < len; j ++) if(s[j] >= '0' && s[j] <= '9') a[i] = a[i] * 10 + s[j] - '0';
        B[i] = len - 4;
    }
    for(int i = 0; i < n; i ++) {
        if(B[i] == 1) {
            if(a[i] == 9) puts("1989");
            else printf("%d\n", 1990 + a[i]);
        } else if(B[i] == 2) {
            if(a[i] == 99) printf("%d\n", 1999);
            else printf("%d\n", 2000 + a[i]);
        } else if(B[i] == 3) {
            if(a[i] >= 99) printf("%d\n", 2000 + a[i]);
            else printf("%d\n", 3000 + a[i]);
        } else if(B[i] == 4) {
            if(a[i] >= 3099) printf("%d\n", a[i]);
            else printf("%d\n", 10000 + a[i]);
        } else if(B[i] == 5) {
            if(a[i] >= 13099) printf("%d\n", a[i]);
            else printf("%d\n", 100000 + a[i]);
        } else if(B[i] == 6) {
            if(a[i] >= 113099) printf("%d\n", a[i]);
            else printf("%d\n", 1000000 + a[i]);
        } else if(B[i] == 7) {
            if(a[i] >= 1113099) printf("%d\n", a[i]);
            else printf("%d\n", 10000000 + a[i]);
        } else if(B[i] == 8) {
            if(a[i] >= 11113099) printf("%d\n", a[i]);
            else printf("%d\n", 100000000 + a[i]);
        } else if(B[i] == 9) {
            if(a[i] >= 111113099) printf("%d\n", a[i]);
            else printf("%d\n", 1000000000 + a[i]);
        }
    }
    return 0;
}