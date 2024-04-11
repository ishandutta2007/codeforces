#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
typedef long long LL;

const int N=1002;
char s[N];
int main() {
    scanf("%s",s+1); int n=strlen(s+1);
    for(int i=1;i<=n;i++) {
        if(s[i]!=s[i+1] && (!(i==n && s[n]=='b'))) printf("1 ");
        else printf("0 ");
    }
}