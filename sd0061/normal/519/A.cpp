#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 205;

char g[N];
map<char , int> h;
void work() {
    int i , j;
    int s1 = 0 , s2 = 0;
    h['q'] = 9;
    h['r'] = 5;
    h['b'] = 3;
    h['n'] = 3;
    h['p'] = 1;
    h['k'] = 0;
    for (i = 0 ; i < 8 ; ++ i) {
        scanf("%s" , g);
        for (j = 0 ; j < 8 ; ++ j)
            if (islower(g[j]))
                s1 += h[g[j]];
            else if (isupper(g[j]))
                s2 += h[g[j] - 'A' + 'a'];
    }
    if (s1 > s2)
        puts("Black");
    else if (s1 == s2)
        puts("Draw");
    else
        puts("White");
}

int main() {
    work();
    return 0;
}