#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define ll long long

using namespace std;

int main() {
    int tcase, n, X, Y, val;
    scanf("%d", &tcase);
    while (tcase--) {
        X = Y = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; i ++) {
            scanf("%d", &val);
            if(val % 2) X ++;
            else Y ++;
        }
        if(X % 2) {
            if((X / 2) % 2) puts("Alice");
            else {
                if(Y % 2) puts("Alice");
                else puts("Bob");
            }
        }
        else {
            if((X / 2) % 2) puts("Bob");
            else puts("Alice");
        }
    }

    return 0;
}