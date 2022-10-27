#include <iostream>
#include <cstring>
using namespace std;
const int N = 1002;
int t, n; char s[102]; 
int main() {
    scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        int bu = 0, odd = 0;
        for (int i = 1; i <= n; i ++) {
            scanf("%s", s);
            int a=0,b=0;
            for(int j=0;s[j];j++) if (s[j] == '0') a++; else b++;
            int len=strlen(s);
            if(len%2==0 && a%2==1 && b%2==1) bu ++; 
            if(len%2==1) odd=1;
        }
        if (bu % 2 == 1 && odd == 0) printf("%d\n", n-1); else printf("%d\n", n);
    }
}