#include<bits/stdc++.h>
#define MAXN 1000020
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
int n,l,m;
ll a[MAXN],b[MAXN],c[MAXN];
mat mul(mat A,mat B)
{
    mat C(A.size(),vec(B[0].size()));
    for(int i=0;i<A.size();i++)
    {
        for(int k=0;k<B.size();k++)
        {
            for(int j=0;j<B[0].size();j++)
            {
                C[i][j]=(C[i][j]+A[i][k]*B[k][j])%MOD;
            }
        }
    }
    return C;
}
mat pow_mod(mat A,ll n)
{
     mat B(A.size(),vec(A.size()));
     for(int i=0;i<A.size();i++)
        B[i][i]=1;
     while(n>0)
     {
         if(n&1) B=mul(B,A);
         A=mul(A,A);
         n>>=1;
     }
     return B;
}
int main()
{
    scanf("%d %d %d",&n,&l,&m);
    for(int i=0;i<n;i++)
        scanf("%I64d",&a[i]);
    for(int i=0;i<n;i++)
        scanf("%I64d",&b[i]);
    for(int i=0;i<n;i++)
        scanf("%I64d",&c[i]);
    mat A(m,vec(m));
    mat B(m,vec(m));
    mat C(m,vec(m));
    for(int i=0;i<m;i++)
        A[0][i]=0;
    for(int i=0;i<n;i++)
        A[0][a[i]%m]++;
    for(int i=1;i<m;i++)
        for(int j=0;j<m;j++)
            A[i][j]=A[0][(j+m-i)%m];
    for(int i=0;i<m;i++)
        C[0][i]=0;
    for(int i=0;i<n;i++)
        C[0][(c[i]+b[i])%m]++;
    for(int i=1;i<m;i++)
        for(int j=0;j<m;j++)
            C[i][j]=C[0][(j+m-i)%m];
    for(int i=0;i<m;i++)
        B[0][i]=0;
    for(int i=0;i<n;i++)
        B[0][b[i]%m]++;
    for(int i=1;i<m;i++)
        for(int j=0;j<m;j++)
            B[i][j]=B[0][(j+m-i)%m];
    B=pow_mod(B,l-2);
    A=mul(A,B);
    A=mul(A,C);
    printf("%I64d\n",A[0][0]);
    return 0;
}