#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;

const int N = 4002;
int sum[N]; char s[N];
int n;
LL c[N*11];

int main(){
    scanf("%d%s",&n,s+1);
    int len=strlen(s+1);
    for(int i=1;i<=len;i++)sum[i]=sum[i-1]+s[i]-'0';

    LL ans = 0;
    for(int i=0;i<len;i++){
        for(int j=i+1;j<=len;j++){
            c[sum[j]-sum[i]]++;
        }
    }


    if(n==0) {
        LL tot = len*(len+1)/2;
        LL ans = c[0]*tot*2 - c[0]*c[0];
        cout<<ans<<endl; return 0;
    }

    for(int i=1;i*i<=n;i++) {
        if(n%i==0) {
            if(i<=sum[len] && (n/i)<=sum[len])
            {
                if(i!=n/i)
                    ans += 2*c[i]*c[n/i];
                else
                    ans += c[i]*c[i];
            }
        }
    }
    cout << ans << endl;
}