#include <iostream>
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;

const int N = 100000+10;
int n; char s[N]; int c[27];
int main(){
    scanf("%d%s",&n,s+1);
    for(int i=1;s[i];i++) c[s[i]-'A']++;
    int mx=0;
    for(int i=0;i<26;i++)mx=max(mx,c[i]);
    int cnt=0;
    for(int i=0;i<26;i++)if(c[i]==mx)cnt++;
    LL ans=1;
    for(int i=1;i<=n;i++)
        ans=ans*cnt%MOD;
    cout<<ans<<endl;
}