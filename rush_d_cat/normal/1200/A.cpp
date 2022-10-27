#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

typedef long long LL;
const int N = 100000 + 10;
char s[N],t[N];

int main() {
    int n; scanf("%d",&n);
    scanf("%s",s+1);
    for(int i=0;i<10;i++)t[i]='0';
    for(int i=1;s[i];i++){
        if(s[i]=='L'){
            for(int j=0;j<10;j++){
                if(t[j]=='0') {
                    t[j]='1'; break;
                }
            }
        } else if(s[i]=='R') {
            for(int j=9;j>=0;j--){
                if(t[j]=='0') {
                    t[j]='1'; break;
                }
            }
        } else {
            t[s[i]-'0'] = '0';
        }
    }
    printf("%s\n", t);
}