#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long LL;
const int N=100000+10;
char s[6][2];
int main(){
    for(int i=0;i<6;i++)
        scanf("%s",s[i]);
    bool ok=0;
    for(int i=1;i<6;i++){
        if(s[i][0]==s[0][0]||s[i][1]==s[0][1])ok=1;
    }
    printf("%s\n", ok?"YES":"NO");
}