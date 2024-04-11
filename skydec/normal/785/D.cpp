#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int P=1000000007;
const int N=410000;
char a[N];int n;
int suml[N],sumr[N];
int fac[N],inv[N];
inline int Pow(int a,int b){
    int c=1;
    for(;b;b>>=1,a=a*1ll*a%P)if(b&1)c=c*1ll*a%P;
    return c;
}
inline void add(int &a,int b){a+=b;if(a>=P)a-=P;}
inline void dec(int &a,int b){a-=b;if(a<0)a+=P;}
void init(int n){
    fac[0]=1;rep(i,1,n)fac[i]=fac[i-1]*1ll*i%P;
    inv[n]=Pow(fac[n],P-2);per(i,n-1,0)inv[i]=inv[i+1]*1ll*(i+1)%P;
}
inline int C(int a,int b){
    if(b>a)return 0;
    return (fac[a]*1ll*inv[b]%P)*1ll*inv[a-b]%P;
}
int main(){
    scanf("%s",a+1);
    n=strlen(a+1);
    init(2*n);
    rep(i,1,n)suml[i]=suml[i-1]+(a[i]=='(');
    per(i,n,1)sumr[i]=sumr[i+1]+(a[i]==')');
    int ans=0;
    rep(i,1,n)if(a[i]=='('){
        int A=suml[i-1];
        int B=sumr[i];
        add(ans,C(A+B,A+1));
    }
    printf("%d\n",ans);
    return 0;
}