#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 200000 + 10;
char s[7];

int main(){
    scanf("%s",s);
    int mx=0;
    for(int i=0;s[i];i++) mx=max(mx,s[i]-'0');
    printf("%d\n", mx); 
    int len=strlen(s);
    for(int i=1;i<=mx;i++){
        bool has=0;
        for(int j=0;s[j];j++){
            if(s[j]!='0') printf("1"), has=1, s[j]--; else if(has) printf("0");
        } 
        printf(" ");
    }
}