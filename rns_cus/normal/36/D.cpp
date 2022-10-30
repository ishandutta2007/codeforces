//D
#include <bits/stdc++.h>
using namespace std;

int TC, k;

int ok(int n, int m){
    if(n > m) {int tmp = n; n = m; m = tmp;}

    if(k  == 1){
        if(n % 2 == 1 || m % 2 == 1) return 1;
        return 0;
    }

    int nn = (n + 1) / (k + 1), nnn = n % (k + 1);
    if(nn % 2 == 0) {
        if(nnn == k) return 1;
        return (m - n) % 2;
    }
    else {
        if(nnn == k) return 1;
        return (m - n + 1) % 2;
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d %d", &TC, &k);
    while(TC --){
        int n, m;
        scanf("%d %d", &n, &m);
        n --, m --;
        if(ok(n, m)) puts("+");
        else puts("-");
    }
    ///return 9;
}