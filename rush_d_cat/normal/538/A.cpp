#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 200000 + 10;
char s[N],t[N]="CODEFORCES";

int main(){
    scanf("%s",s);
    int len=strlen(s);
    
    int pre=0;
    for(int i=0;s[i];i++){
        if(s[i]==t[pre]){
            pre++; 
        } else {
            break;
        }
        if(pre==10) break;
    }

    int suf=0;
    for(int i=len-1;i>=0;i--){
        if(s[i]==t[9-suf]){
            suf++;
        } else {
            break;
        }
        if(suf==10) break;
    }
    printf("%s\n", pre+suf>=10?"YES":"NO");
}