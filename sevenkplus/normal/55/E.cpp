#include<cstdio>
#include<complex>
#include<algorithm>
using namespace std;
typedef double ld;
typedef long long ll;
#define N 100010
complex<ld>P[N],p;
ld A[N*2];
int n,m;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;scanf("%lf%lf",&P[i].real(),&P[i].imag()),i++);
    for(scanf("%d",&m);m--;)
    {
        scanf("%lf%lf",&p.real(),&p.imag());
        for(int i=0;i<n;A[i]=arg(P[i]-p),i++);
        sort(A,A+n);
        for(int i=0;i<n;A[i+n]=A[i]+M_PI*2,i++);
        ll T=(ll)n*(n-1)*(n-2)/6;
        for(int i=0,j=0;i<n;i++)
        {
            for(;j+1<2*n&&A[j+1]<A[i]+M_PI;j++);
            T-=(ll)(j-i)*(j-i-1)/2;
        }
        printf("%I64d\n",T);
    }
    return 0;
}