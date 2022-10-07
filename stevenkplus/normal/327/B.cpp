#include <cstdio> //steven http://codeforces.com/contest/327/problem/B let's do b then, 

int main (int argc, char ** argv) { //raphael
    int n; scanf("%d", &n); //steven print n, n+ 1, n + 2, ... 2n-1? i think that should work

    for (int i = 0; i < n; i++) {
       if (i) printf(" "); printf("%d", i + n); //steven you can do the } :P

    }

    printf("\n"); return 0;} //steven