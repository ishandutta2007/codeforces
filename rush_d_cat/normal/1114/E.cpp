#include <iostream>
#include <cstring>
#include <bitset>
#include <algorithm>
#include <unordered_map>
#include <map>
using namespace std;

const int N=1000000+10;
int n, c;
int ask(int x) {
    ++ c;
    printf("> %d\n", x);
    fflush(stdout);
    int t; scanf("%d", &t); return t;
}
int gcd(int x,int y){
    return y==0?x:gcd(y,x%y);
}

int main() {
    scanf("%d",&n);
    int l=-1,r=1e9;
    while(r-l>1){
        int mid=(l+r)>>1;
        if(ask(mid))
            l=mid;
        else
            r=mid;
    }
    int mx = l+1;
    int g=0;
    while(c<60) {
        ++ c;
        int p = (1LL*(rand()%1000000)*(rand()%1000000))%n+1;
        p = (p%n + n) % n + 1;
        printf("? %d\n", p);
        fflush(stdout);
        int x; scanf("%d", &x);
        g = gcd(g, mx-x);
        //printf("g=%d\n", g);
    }
    printf("! %lld %d\n", 1LL*mx - 1LL*(n-1)*g, g);
    fflush(stdout);
}
/*
14 4 9 -1
*/