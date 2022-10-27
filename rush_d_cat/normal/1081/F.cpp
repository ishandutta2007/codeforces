#include <iostream>
using namespace std;
const int N = 302;
int n,t,suf[N];
int now;
void ask(int x) {
    // [a b] [c d]
    // a+b=x, c+d=n-x, b+d=now
    // b+c=c1
    /*
    c - d = c1 - now
    c + d = n - x
    d = [(n-x) - (c1-now)] / 2
    */ 

    for(int i=1;i<=16;i++){
        int tmp = now;
        printf("? %d %d\n", x+1, n); fflush(stdout); int c1; scanf("%d",&c1);
        printf("? %d %d\n", 1, n);   fflush(stdout); int c2; scanf("%d",&c2);
        if (c2 == now && i<16) continue; 
        now = c2;
        suf[x+1] = ((n-x)-(c1-tmp))/2;
        break;
    }
    // x-1 - pre
}

int main() {
    scanf("%d %d",&n,&t);
    now = t;
    suf[1] = t;
    for(int i=1;i<n;i++){
        ask(i);
    }
    printf("! ");
    for(int i=1;i<=n;i++){
        if(suf[i]==suf[i+1]) printf("0");
        else printf("1");
    }
    fflush(stdout);
}