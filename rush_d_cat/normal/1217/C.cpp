#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t,nex[N];
char s[N];
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%s",s+1);
        int n=strlen(s+1);
        nex[n+1]=n+1;
        for(int i=n;i>=1;i--) {
            if(s[i]=='0') nex[i]=nex[i+1];
            else nex[i]=i;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            int now=0;
            for(int j=nex[i];j<=min(n,nex[i]+30);j++){
                now=now*2+s[j]-'0';
                if(now==j-i+1) ans++;
            }
        }
        printf("%d\n", ans);
    }
}