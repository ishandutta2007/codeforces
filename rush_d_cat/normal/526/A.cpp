#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=100+10;
int n; char s[N*10];

int main() {
    scanf("%d%s",&n,s+1);
    for(int d=1;d<=n;d++)
    for(int i=1;i<=n;i++){
        if(s[i]=='*') {
            if(s[i]=='*' && s[i+d]=='*' && s[i+2*d]=='*' && s[i+3*d]=='*' && s[i+4*d]=='*')
                return !printf("yes\n");
        }
    }
    printf("no\n");
}