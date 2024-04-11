#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int main() {
    int n, m, T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&n,&m);
        if (n == 1 && m == 1) {
            puts("0");
        } else if (n == 1 || m == 1) {
            puts("1");
        } else {
            puts("2");
        }
    } 
}