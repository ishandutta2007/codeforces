#include<bits/stdc++.h>
#define N 10000
#define Pii pair<long long,long long>
#define S second
#define F first
#define testN 1
using namespace std;
long long pr[19]=
{
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67
};
long long A[2][1000009],b;
long long f[100];
long long mod=1000000007;
long long X(long long x)
{
long long a=0;
long long b=x;
for (long long j=0; j<19; j++)
            {
                long long z=0;
                while(b%pr[j]==0) {b/=pr[j]; z++;}
                if(z&1) a|=(1<<j);
            }
        return a;
}
long long P[1000009],P1[1000009];
main()
{
    P[0]=1;
    P1[0]=0;
    P[1]=1;
    P1[1]=1;

    long long n;
    cin>>n;
    for (long long i=2; i<=n; i++)
    {
        P[i]=(P[i-1]*2)%mod;
        P1[i]=P[i];
    }
    for (long long i=0; i<n; i++)
        {scanf("%d",&b);
        long long a=0;
        f[b]++;

        }
        A[0][0]=1;
    for (long long i=1; i<=70; i++)
    {

     long long c=X(i);

     for (long long j=0; j<(1<<19); j++)
            A[i%2][(j^c)]=((A[(i+1)%2][(j^c)]*P[f[i]]+A[(i+1)%2][j]*P1[f[i]]))%mod;

    }
    cout<<(A[0][0]+mod-1)%mod<<endl;

}