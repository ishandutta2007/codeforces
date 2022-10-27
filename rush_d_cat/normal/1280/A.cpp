#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
const LL MOD=1e9+7;
const int N=10000000+10;
int t; char s[N];
int main(){
    scanf("%d",&t);
    while(t--){
        int x; scanf("%d",&x);
        scanf("%s",s+1);
        LL n=strlen(s+1);
        bool flag=0;
        for(int i=1;i<=x;i++){
            int pos=i+1;
            int c=s[i]-'0';
            int len=n-pos+1;
            if(flag==0){
                for(int j=1;j<=c-1;j++){
                    for(int k=n+1;k<=n+len;k++) s[k]=s[k-len];
                    n+=len;
                }
                if(n>=x) flag=1;
            } else {
                n=(n+1LL*(c-1)*len)%MOD;
            }
            n=(n%MOD+MOD)%MOD;
        }
        printf("%lld\n", n);
    }
}