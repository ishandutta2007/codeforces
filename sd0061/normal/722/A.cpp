#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int main() {
    int H , h , m;
    scanf("%d\n%d:%d" , &H , &h , &m);
    char s[10] , t[10] , r[10];
    sprintf(s , "%02d:%02d" , h , m);
    int res = 1 << 30;
    int L = 1 , R = 12;
    if (H == 24) L = 0 , R = 23;
    for (int x = L ; x <= R ; ++ x) {
        for (int y = 0 ; y < 60 ; ++ y) {
            sprintf(t , "%02d:%02d" , x , y);
            int w = 0;
            for (int k = 0 ; s[k] ; ++ k) {
                w += (s[k] != t[k]);
            }
            if (w < res) {
                res = w;
                strcpy(r , t);
            }
        }
    }
    puts(r);
}