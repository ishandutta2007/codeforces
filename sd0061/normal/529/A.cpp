#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2000005;
int n , s[N] , L[N];
char str[N] , res[N];

int sa[N] , t1[N] , t2[N] , c[N];
void buildsa(char *s , int n , int m) {
    int i , k , p , a1 , a2 , *x = t1 , *y = t2;
    memset(c , 0 , m << 2);
    for (i = 0 ; i < n ; ++ i) ++ c[x[i] = s[i]];
    for (i = 1 ; i < m ; ++ i) c[i] += c[i - 1];
    for (i = n - 1 ; i >= 0 ; -- i) sa[-- c[x[i]]] = i;
    for (k = 1 ; k < n ; k <<= 1) {
        p = 0;
        //for (i = n - k ; i < n ; ++ i) y[p ++] = i;
        for (i = 0 ; i < n ; ++ i)
            y[p ++] = (sa[i] + n - k) % n;
        memset(c , 0 , m << 2);
        for (i = 0 ; i < n ; ++ i) ++ c[x[y[i]]];
        for (i = 1 ; i < m ; ++ i) c[i] += c[i - 1];
        for (i = n - 1 ; i >= 0 ; -- i) sa[-- c[x[y[i]]]] = y[i];
        swap(x , y) , p = 1 , x[sa[0]] = 0;
        for (i = 1 ; i < n ; ++ i) {
            a1 = y[(sa[i - 1] + k) % n];
            a2 = y[(sa[i] + k) % n];
            x[sa[i]] = (a1 == a2 && y[sa[i - 1]] == y[sa[i]]) ? p - 1 : p ++;
        }
        if (p >= n) break; m = p;
    }
}
int Q[N] , top , bot;
int m;
void work() {
    int i , j , y; char c;
    while (c = getchar() , ~c && c != '\n')
        str[n ++] = c;
    for (i = n ; i < n + n ; ++ i)
        str[i] = str[i - n];
    for (i = 0 ; i < n + n ; ++ i)
        s[i + 1] = s[i] + (str[i] == '(' ? 1 : -1);
    m = n;
    buildsa(str , m , 128);
    top = 0 , bot = -1;
    for (i = 1 ; i <= n + n ; ++ i) {
        while (top <= bot && Q[top] < i - n + 1)
            ++ top;
        while (top <= bot && s[i] <= s[Q[bot]])
            -- bot;
        Q[++ bot] = i;
        if (i >= n)
            L[i - n] = s[Q[top]];
    }
    y = min(s[n] , 0);
    for (i = 0 ; i < m ; ++ i) {
        j = sa[i];
        if (j >= n) continue;
        if (L[j] >= s[j] + y)
            break;
    }
    m = 0;
    for (i = 0 ; i < -s[n] ; ++ i) res[m ++] = '(';
    for (i = 0 ; i < n ; ++ i) res[m ++] = str[i + j];
    for (i = 0 ; i < s[n] ; ++ i) res[m ++] = ')';
    puts(res);
}

int main () {
    work();
    return 0;
}