#include <iostream>
using namespace std;
const int N = 100000 + 10;
int n,k;
char s[N];
int main() {
    scanf("%d%d%s",&n,&k,s+1);
    int i = 1;
    while(k--) {
        bool ok = 0, gg = 0;
        for(;i<n;i++){
            if(s[i]=='4'&&s[i+1]=='7') {
                ok = 1;
                if(i%2==1) s[i+1]='4';
                if(i%2==0) {
                    s[i]='7'; 
                    if(s[i-1]=='4') {
                        if(k%2==1) s[i]='4';
                        gg = 1;
                    }
                }
                break;
            }
        }
        if(gg==1) break;
        if(ok==0) break;
    }
    printf("%s\n", s+1);
}
/*
4777777
4477777
4777777

477 -> 777
477 -> 447 -> 477
474 -> 774
*/