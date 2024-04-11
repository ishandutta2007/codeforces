#include <iostream>
#include <cstring>
using namespace std;
int T; char s[102];
int f(char c) {
    if('0'<=c && c<='9') return 1;
    if('a'<=c && c<='z') return 2;
    if('A'<=c && c<='Z') return 4;
}
int state(char * s) {
    int ans = 0;
    for(int i=0;s[i];i++) {
        ans |= f(s[i]);
    }
    return ans;
}
int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%s", s);
        int mask = state(s);
        if (mask == 1) {
            s[0]='a',s[1]='A';
        } else if (mask == 2) {
            s[0]='0',s[1]='A';
        } else if (mask == 4) {
            s[0]='0',s[1]='a';
        } else if(mask==7) {
        } else if(mask==3){
            int c[6]={0};
            for(int i=0;s[i];i++) c[f(s[i])] ++;
            for(int i=0;s[i];i++) {
                if(c[f(s[i])] >= 2) {
                    s[i] = 'A';break;
                }
            }
        } else if(mask==5){
            int c[6]={0};
            for(int i=0;s[i];i++) c[f(s[i])] ++;
            for(int i=0;s[i];i++) {
                if(c[f(s[i])] >= 2) {
                    s[i] = 'a';break;
                }
            }
        } else if(mask==6){
            int c[6]={0};
            for(int i=0;s[i];i++) c[f(s[i])] ++;
            for(int i=0;s[i];i++) {
                if(c[f(s[i])] >= 2) {
                    s[i] = '0';break;
                }
            }
        }
        printf("%s\n", s);
    }
}