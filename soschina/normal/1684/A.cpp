#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 10;

int q, n;
char s[N];

int main(){
    scanf("%d", &q);
    while(q--){
        scanf("%s", s);
        n = strlen(s);
        if(n == 2){
            puts(s + 1);
            continue;
        }
        char ans = '9';
        for (int i = 0; i < n; i++)
            ans = min(ans, s[i]);
        putchar(ans);
        putchar('\n');
    }
    return 0;
}