#include <iostream>
#include <cstring>
using namespace std;
const int N = 100000 + 10;
int n;
char s[N];
int c[N];

int main() {
    scanf("%d %s", &n, s+1);
    if(n==1) {
        return !printf("Yes\n");
    }
    for(int i=1;i<=n;i++) {
        c[s[i]] ++;
    }
    bool ok = 0;
    for(int i=0;i<N;i++) {
        if(c[i]>1) ok = 1;
    }
    printf("%s\n", ok?"Yes":"No");
}