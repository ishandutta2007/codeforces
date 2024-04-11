#include <iostream>
using namespace std;
typedef long long LL;
int n;
LL x, y;
char s[300000+10];
LL solve() {
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='0'&&s[i-1]!='0') cnt++;
    }
    if(cnt==0) return 0;
    return min(y*cnt, (cnt-1)*x+y);
}
int main() {
    scanf("%d %lld %lld", &n, &x, &y);
    scanf("%s", s+1);
    LL ans=solve();
    for(int i=1;i<=n;i++){
        if(s[i]=='0') s[i]='1';
        else s[i]='0';
    }
    ans=min(ans,solve()+y);
    cout<<ans<<endl;
}