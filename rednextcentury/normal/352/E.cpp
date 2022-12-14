#include <bits/stdc++.h>
#define REP(i,n) for (long long i = 1; i <= n; i++)
using namespace std;

long long K;
typedef long long ll;
typedef vector<vector<long long> > matrix;
const long long MOD = 2000000001;
long long no=MOD;
long long n;
matrix mul(matrix A, matrix B)
{
    K=2*n;
    matrix C(K+1, vector<long long>(K+1));

    for (long long i=0;i<=K;i++)
        for (long long j=0;j<=K;j++)
            C[i][j]=MOD;

        for (long long i=0;i<=K;i++)
        {
            for (long long j=0;j<=K;j++)
            {
                
                for (long long k=0;k<=K;k++)
                    C[i][j] = min(C[i][j] , A[i][k] + B[k][j]);
            }
        }
    return C;
}

// computes A ^ p
matrix pow(matrix A, long long p)
{
    if (p == 1)
        return A;
    if (p % 2)
        return mul(A, pow(A, p-1));
    matrix X = pow(A, p/2);
    return mul(X, X);
}
long long down[30][30];
long long m;
long long up[30][30];
long long a[1000];
long long b[1000];
long long nope[1001];
void calc_cost(long long x)
{
    long long mn=0,c=0;
    long long cost=0;
    for (long long i=0;i<n;i++)
    {
        if ((1<<i)&x)
            cost+=b[i],c--;
        else
            cost+=a[i],c++;
        mn=min(mn,c);
    }
    if (c<0)
        down[-mn][-c]=min(down[-mn][-c],cost);
    else if (c==0)
        nope[-mn]=min(nope[-mn],cost);
    else
        up[-mn][c]=min(up[-mn][c],cost);
}
long long solve()
{
    // create vector F1
    long long K=2*n;
    vector<ll> F1(K+1);
    matrix T(K+1, vector<long long>(K+1));
    for (long long i=0;i<=K;i++)
    {
        for (long long j=0;j<=K;j++)
        {
            T[i][j]=no;
            if (abs(i-j)>n)continue;
            if (i==j)
                for (long long x=min(n,i);x>=0;x--)
                    T[i][j]=min(T[i][j],nope[x]);
            else if (i<j)
            {
                for (long long x=min(n,i);x>=0;x--)
                    T[i][j]=min(T[i][j],up[x][(j-i)]);
            }
            else
            {
                for (long long x=min(n,i);x>=0;x--)
                    T[i][j]=min(T[i][j],down[x][(i-j)]);
            }
        }
    }

    T = pow(T, m);

    return T[0][0];
}
int main()
{
    cin>>n>>m;
    for (long long i=0;i<n;i++)cin>>a[i];
    for (long long i=0;i<n;i++)cin>>b[i];
    for (long long i=0;i<=20;i++)
        for (long long j=0;j<=20;j++)
            up[i][j]=down[i][j]=MOD;
    for (int i=0;i<=20;i++)
        nope[i]=MOD;
    for (long long i=0;i<(1<<n);i++)
        calc_cost(i);
    cout<<solve()<<endl;
}