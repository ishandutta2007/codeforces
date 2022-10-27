#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
const int N=10002;
int n;
char s[N];
int main() {
    scanf("%d %s",&n, s+1);
    int cnt=0;
    s[0]=s[n+1]='0';
    bool ok=1;
    for(int i=0;i<=n+1;i++) {
        if(i>=1&&i<=n&&s[i]=='0'&&s[i+1]=='0'&&s[i-1]=='0') ok=0;
        if(i<=n-1&&s[i]=='1'&&s[i+1]=='1') ok=0;
    } 
    printf("%s\n", ok?"Yes":"No");
}