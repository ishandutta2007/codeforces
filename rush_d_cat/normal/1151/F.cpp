#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N=100+10;

const int Mod = 1000000007;
ll mpow(ll a,ll x){
    if(x==0)return 1;
    ll t=mpow(a,x>>1);
    if(x%2==0)return t*t%Mod;
    return t*t%Mod*a%Mod;
}
int D;
struct Matrix
{
    int a[102][102];
    Matrix()
    {
        memset(a,0,sizeof(a));
    }
    void init()
    {
        for(int i=0;i<D;i++)
            for(int j=0;j<D;j++)
                a[i][j]=(i==j);
    }
    Matrix operator * (const Matrix &B)const
    {
        Matrix C; 
        for(int i=0;i<D;i++)
            for(int j=0;j<D;j++)
                for(int k=0;k<D;k++)
                    C.a[i][j]=(C.a[i][j]+1LL*a[i][k]*B.a[k][j])%Mod;
        return C;
    }
    Matrix operator ^ (const ll &p)const
    {
        Matrix A=(*this),res;
        res.init();
        ll t=p;
        while(t)
        {
            if(t&1)res=res*A;
            A=A*A;
            t>>=1;
        }
        return res;
    }
    void prt(){
        printf("mat\n");
        for(int i=0;i<D;i++){
            for(int j=0;j<D;j++)
                printf("%d ", a[i][j]);
            printf("\n");
        }
    }
} M;
int n,k;
int a[N];
int main() {
    scanf("%d%d",&n,&k);
    int sz=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]); if(a[i]==0)sz++;
    }
    int cnt=0;
    for(int i=1;i<=sz;i++){
        if(a[i]==0)cnt++;
    }
    D=sz+1;
    ll demon=mpow(n*(n-1)/2,Mod-2);
    for(int i=0;i<=sz;i++){
        // sz    [i, sz-i]
        // n-sz  [sz-i, n+i-2*sz]
        // 00,11
        
        // 01
        ll p10=i*(n+i-2*sz); 
        // 10
        ll p01=(sz-i)*(sz-i);
        ll p00=n*(n-1)/2 - p01 - p10;
        if(i<sz)M.a[i+1][i]=p01*demon%Mod;
        if(i>0) M.a[i-1][i]=p10*demon%Mod;
        M.a[i][i]=p00*demon%Mod;
    }
    //M.prt();
    M=M^k;
    //M.prt();
    ll ans=M.a[sz][cnt];
    cout<<ans<<endl;
}