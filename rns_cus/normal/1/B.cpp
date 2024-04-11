#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;

char s[100];

void f(int x){
    if(x) {f((x-1)/26); putchar('A'+(x-1)%26);}
}

int main(){
//    freopen("in.txt", "r", stdin);
    int TC, r, c;
    for(scanf("%d", &TC); TC; TC--){
        scanf("%s", s);
        if(sscanf(s, "%*[A-Z]%d%*[A-Z]%d", &r, &c)==2){
            f(c); printf("%d\n", r);
        }else{
            c = 0;
            for(int i=0; s[i]>='A' && s[i]<='Z'; i++){
                c = c*26 + s[i]-'A'+1;
            }
            printf("R%dC%d\n", r, c);
        }
    }
    return 0;
}