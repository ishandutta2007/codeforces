#include<bits/stdc++.h>
using namespace std;
inline int read(){ int x=0; char c=getchar();
    for(;!isdigit(c);c=getchar());
    for(;isdigit(c);c=getchar()) x=x*10+c-'0'; return x;
} char s[15];
inline int get(){ int x=read();
    for(int i=1,t;i<=x;++i) scanf("%s",s); return x;
}
int main(){
    while(1){
        puts("next 0"),fflush(stdout),get();
        puts("next 0 1"),fflush(stdout);
        if(get()==2) break;
    }
    while(1){
        puts("next 0 1 2 3 4 5 6 7 8 9"),fflush(stdout);
        if(get()==1) break;
    } return puts("done"),fflush(stdout),0;
}