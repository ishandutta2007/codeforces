#include <bits/stdc++.h>
#define int long long

using namespace std;
signed main() {    
    int T;
    scanf("%lld",&T);
    while (T--) {
        int n;
        cin>>n;
        int a[50]={};
        int cnt=0;

        while (n) a[++cnt]=n%10,n/=10;
        int ans=1e9; 
        for (int i=1;i<=cnt/2;i++) swap(a[i],a[cnt-i+1]);
        int pw=1; 
        for (int k=0;k<=60;k++) {
            int pww=pw,b[50]={},len=0; 
           // cout<<pw<<' ';
            while (pww) {
                b[++len]=pww%10; pww/=10; 
            }

            for (int j=1;j<=len/2;j++) swap(b[j],b[len-j+1]);
              //  cout<<'\n';
            int pos=0; 
            for (int j=1;j<=cnt;j++) {
                if (a[j]==b[pos+1]&&pos<=len-1) pos++; 
            }
            ans=min(ans,cnt-pos+len-pos); 
            pw*=2; 
        }
        cout<<ans<<'\n'; 
    }
    return 0; 
}