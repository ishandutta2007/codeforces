#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=1000000+10;
char s[N],t[N],str[N];
void read(char *s) {
    scanf("%s",str);
    bool ok=0; int tot=0;
    for(int i=0;str[i];i++) {
        if(str[i]!='0'){
            ok=1;
        }
        if(ok)s[tot++]=str[i];
    }
}
int main() {
    read(s), read(t);
    int slen=strlen(s);
    int tlen=strlen(t);

    if(slen<tlen) {
        printf("<\n");
    } else if(slen>tlen){
        printf(">\n");
    } else {
        for(int i=0;s[i];i++){
            if(s[i]<t[i]){
                return !printf("<\n");
            } 
            if(s[i]>t[i]){
                return !printf(">\n");
            }
        }
        printf("=\n");
    }
}