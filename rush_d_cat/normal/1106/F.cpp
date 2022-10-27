#include <iostream>
#include <map>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int Mod = 998244353;
typedef long long ll;
typedef long long LL;
const int N = 10000000 + 10;
/** */
bitset<N> prime;
int p[N],pri[N];
int k,cnt;
 
void isprime()
{
    prime.set();
    for(int i=2; i<N; i++)
    {
        if(prime[i])
        {
            p[k++] = i;
            for(int j=i+i; j<N; j+=i)
                prime[j] = false;
        }
    }
}
 
void Divide(LL n)
{
    cnt = 0;
    LL t = (LL)sqrt(1.0*n);
    for(int i=0; p[i]<=t; i++)
    {
        if(n%p[i]==0)
        {
            pri[cnt++] = p[i];
            while(n%p[i]==0) n /= p[i];
        }
    }
    if(n > 1)
        pri[cnt++] = n;
}
 
LL multi(LL a,LL b,LL m)
{
    LL ans = 0;
    a %= m;
    while(b)
    {
        if(b & 1)
        {
            ans = (ans + a) % m;
            b--;
        }
        b >>= 1;
        a = (a + a) % m;
    }
    return ans;
}
 
LL quick_mod(LL a,LL b,LL m)
{
    LL ans = 1;
    a %= m;
    while(b)
    {
        if(b&1)
        {
            ans = multi(ans,a,m);
            b--;
        }
        b >>= 1;
        a = multi(a,a,m);
    }
    return ans;
}
 
LL broot(LL p)
{
    Divide(p-1);
    for(int g=2 ;; g++)
    {
        bool flag = true;
        for(int i=0; i<cnt; i++)
        {
            LL t = (p - 1) / pri[i];
            if(quick_mod(g,t,p) == 1)
            {
                flag = false;
                break;
            }
        }
        if(flag) return g;
    }
}
/** */
 
/** Baby_Step */
 
LL gcd(LL a,LL b)
{
    return b ? gcd(b,a%b):a;
}
 
void extend_Euclid(LL a,LL b,LL &x,LL &y)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        return;
    }
    extend_Euclid(b,a%b,x,y);
    LL tmp = x;
    x = y;
    y = tmp - (a / b) * y;
}
 
LL Inv(LL a,LL p)
{
    return quick_mod(a,p-2,p);
}
 
LL Baby_Step(LL A,LL B,LL C)
{
    map<LL,int> mp;
    LL M = ceil(sqrt(1.0*C));
    LL t = Inv(quick_mod(A,M,C),C);
    LL ans = 1;
    for(int i=0; i<M; i++)
    {
        if(!mp.count(ans))
            mp[ans] = i;
        ans = multi(ans,A,C);
    }
    for(int i=0; i<M; i++)
    {
        if(mp.count(B))
            return i * M + mp[B];
        B = multi(B,t,C);
    }
    return -1;
}
/** Baby_Step */

LL ans[1005];
void Work(LL A,LL B,LL C)
{
    LL root = broot(C);
    LL t1 = Baby_Step(root,B,C);
    LL t2 = C - 1;
    LL d = gcd(A,t2);
    if(t1 % d)
    {
        puts("-1");
        return;
    }
    LL x,y;
    extend_Euclid(A,t2,x,y);
    t2 /= d;
    t1 /= d;
    ans[0] = (x * t1 % t2 + t2) % t2;
    ans[0] = quick_mod(root,ans[0],C);
    cout << ans[0] << endl;
}
 
typedef long long ll;
int n,m,d,b[102];
struct Matrix
{
    int a[102][102];
    Matrix()
    {
        memset(a,0,sizeof(a));
    }
    void init()
    {
        for(int i=0;i<d;i++)
            for(int j=0;j<d;j++)
                a[i][j]=(i==j);
    }
    Matrix operator * (const Matrix &B)const
    {
        Matrix C;
        for(int i=0;i<d;i++)
            for(int j=0;j<d;j++)
                for(int k=0;k<d;k++)
                    C.a[i][j]=(C.a[i][j]+1LL*a[i][k]*B.a[k][j])%(Mod-1);
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
        for(int i=0;i<d;i++) {
            for(int j=0;j<d;j++) {
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }
    }
} M;

ll mpow(ll a, ll x) {
    if (x==0) return 1;
    ll tmp = mpow(a,x>>1);
    if (x%2==0) return tmp*tmp%Mod;
    return tmp*tmp%Mod * a % Mod;
}

int main() {
    isprime();
    scanf("%d", &d);
    for(int i=0;i<d;i++) {
        scanf("%d", &b[i]);
    }
    M = Matrix();
    for(int i=0;i<d;i++) {
        M.a[0][i] = b[i];
    }
    for(int i=1;i<d;i++) {
        M.a[i][i-1] = 1;
    }

    scanf("%d %d",&n,&m);
    M = M ^ (n-d);
    int K = M.a[0][0]; // x  = 1 / m^k
    Work(K,m,Mod);
}

/*
x^a=b
*/