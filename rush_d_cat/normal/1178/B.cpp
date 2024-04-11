#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
typedef long long LL;
const int N = 1000000 + 10;
char s[N];
int n;LL pre[N],suf[N];
int main() {
    scanf("%s",s+1); n=strlen(s+1);
    for(int i=2;i<=n;i++) {
        if(s[i]=='v' && s[i-1]=='v') pre[i]=pre[i-1]+1;
        else pre[i]=pre[i-1];
    }
    for(int i=n-1;i>=1;i--){
        if(s[i]=='v' && s[i+1]=='v') suf[i]=suf[i+1]+1;
        else suf[i]=suf[i+1];
    }
    LL ans=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='o')ans=ans+pre[i-1]*suf[i+1];
    }
    cout<<ans<<endl;
}