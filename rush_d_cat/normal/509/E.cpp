#include <iostream>
#include <cstring>
using namespace std;
const int N=500000+10;
typedef long long LL;
char s[N]; int n;
LL a[N],pre[N],suf[N],sum[N];

bool chk(char c){
    return c=='I'||c=='E'||c=='A'||c=='O'||c=='U'||c=='Y';
}
int main() {
    scanf("%s",s+1); n=strlen(s+1);
    for(int i=1;i<=n;i++){
        a[i] = chk(s[i]); 
    }
    for(int i=1;i<=n;i++) sum[i] = sum[i-1] + a[i];
    for(int i=1;i<=n;i++) sum[i] = sum[i-1] + sum[i];

    double ans=0;
    LL A=0,B=0;
    for(int i=1;i<=n;i++) {
        A = (sum[n] - sum[i-1]) - (sum[n-i]);
        B ++;
        ans += 1.0 * A / B;
    }
    printf("%.8f\n", ans);
}