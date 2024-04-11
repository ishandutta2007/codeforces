#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include<cmath>
#include <cstring>
#include <map>
#define fi first
#define se second
#define INF 0x3f3f3f3f
using namespace std;
const int MOD = 1e9+7;
const int MAX_P = 2e4+10;
const int maxn =500+10;
const int MAX_V = 5e5+10;
const int maxv = 1e6+10;
typedef long long LL;
typedef long long ll;
typedef pair<int,int> Pair;
const int Mod = 1000000006;
struct Matrix
{
    int a[6][6];
    Matrix()
    {
        memset(a,0,sizeof(a));
    }
    void init()
    {
        for(int i=0;i<5;i++)
            for(int j=0;j<5;j++)
                a[i][j]=(i==j);
    }
    Matrix operator * (const Matrix &B)const
    {
        Matrix C;
        for(int i=0;i<5;i++)
            for(int j=0;j<5;j++)
                for(int k=0;k<5;k++)
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
    void prt() {
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++)
                printf("%d ", a[i][j]);
            printf("\n");
        }
    }
} M;

LL gcd(LL x,LL y){
    return y==0?x:gcd(y,x%y);
}
LL power_mod(LL x,LL n, int mod){
   LL res =1;
   while (n) {
      if(n&1)res = res*x % mod;
      x = x*x %mod;
      n >>=1;
   }
   return res;
}

LL bsgs(LL A,LL C,LL mod){
   A %= mod;C %= mod;
   if(C==1)return 0;
   LL cnt =0;
   LL tmp = 1;
   for(LL g = gcd(A,mod) ; g != 1 ; g = gcd(A,mod)){
      if(C % g)return -1;//
      C /=g ; mod/=g ; tmp = tmp*A/g%mod;
      ++cnt;
      if(C == tmp)return cnt;
   }
   //a^xa^cnt=C (mod m)a^cnt = tmp;
   LL T = (LL)sqrt(0.5+mod);
   LL b = C;
   map<LL,LL> hash;
   hash[b] = 0;
   for(int i=1 ; i<=T ; ++i){
      b = b*A%mod;//modLL
      hash[b] = i;
   }
   A = power_mod(A,T,mod);
   for(int u =1 ; u<=T ; ++u){
      tmp = tmp*A %mod;
      if(hash.count(tmp))return u*T-hash[tmp]+cnt;
   }
   return -1;
}

int main() {
    //cout<<power_mod(2,385273928,MOD) << endl;
    //cout << bsgs(2,8,MOD) << endl;
    LL n,f1,f2,f3,c; cin>>n>>f1>>f2>>f3>>c; 
    f1=bsgs(5,f1,MOD),f2=bsgs(5,f2,MOD); f3=bsgs(5,f3,MOD);
    c=bsgs(5,c,MOD);
    //cout<<f1<<" "<<f2<<" "<<f3<<" "<<c<<endl;
    M.a[0][0]=M.a[0][1]=M.a[0][2]=1,M.a[0][3]=2*c%Mod;
    M.a[1][0]=1; M.a[2][1]=1; M.a[3][3]=1,M.a[3][4]=1; M.a[4][4]=1;
    //M.prt();
    M=M^(n-3);
    //printf("ok\n");
    LL ans=f3*M.a[0][0]%(Mod) + f2*M.a[0][1]%(Mod) + f1*M.a[0][2]%(Mod) + M.a[0][3] + M.a[0][4]; ans = ans % (Mod);
    cout << power_mod(5,ans,MOD) << endl;

}