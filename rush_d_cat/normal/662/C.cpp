#include <iostream>
using namespace std;
const int mod = 1000000007;
const int N = 3000000+10;
char s[N];
int count(int x) {int r=0;while(x){if(x%2)r++;x/=2;}return r;}
void FWT(int a[],int n) {
    for(int d=1;d<n;d<<=1)
        for(int m=d<<1,i=0;i<n;i+=m)
            for(int j=0;j<d;j++) {
                int x=a[i+j],y=a[i+j+d];
                a[i+j]=(x+y)%mod,a[i+j+d]=(x-y+mod)%mod;
            }
}
void UFWT(int a[],int n) {
    int rev=(mod+1)/2;
    for(int d=1;d<n;d<<=1)
        for(int m=d<<1,i=0;i<n;i+=m)
            for(int j=0;j<d;j++) {
                int x=a[i+j],y=a[i+j+d];
                a[i+j]=1LL*(x+y)*rev%mod,a[i+j+d]=(1LL*(x-y)*rev%mod+mod)%mod;
            }
}
void solve(int a[],int b[],int n) {
    FWT(a,n); FWT(b,n);
    for(int i=0;i<n;i++) a[i]=1LL*a[i]*b[i]%mod;
    UFWT(a,n);
}
int n, m;
int mp[N], F[N], G[N];
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%s",s);
        for(int j=0;j<m;j++){
            mp[j]=(mp[j]<<1)|(s[j]-'0');
        }
    }
    for(int i=0;i<m;i++) F[mp[i]]++;
    for(int i=0;i<1<<n;i++) G[i]=min(count(i),n-count(i));
    solve(F,G,1<<n);
    int ret=mod; for(int i=0;i<1<<n;i++) ret=min(ret,F[i]);
    cout<<ret<<endl;
}