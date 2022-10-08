#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
#define P 1000000007
#define N 1000010
int f0[N],f1[N],lb[N],rw[N],g0[N],g1[N],n,k;
char a[N];
int main()
{
    scanf("%d%d%s",&n,&k,a);
    f0[0]=1;
    for(int i=1,cs=1,le=0;i<=n;i++)
    {
        // Last B = i
        // Next To Last B >= i-k
        if(a[i-1]=='B')f0[i]=0;else f0[i]=cs;
        if(i-le>=k)cs=(cs-f0[le]+P)%P,le++;
        if(a[i-1]=='W')cs=0,le=i;
        (cs+=f0[i])%=P;
    }
    f1[n]=1;
    for(int i=n-1,cs=1,ri=n;i>=0;i--)
    {
        if(a[i]=='W')f1[i]=0;else f1[i]=cs;
        if(ri-i>=k)cs=(cs-f1[ri]+P)%P,ri--;
        if(a[i]=='B')cs=0,ri=i;
        (cs+=f1[i])%=P;
    }
    //for(int i=0;i<=n;i++)printf("%d %d\n",f0[i],f1[i]);
    for(int i=0,lbl=-1;i<n;i++)
    {
        if(a[i]=='W')lbl=i;
        lb[i]=lbl;
    }
    for(int i=n-1,rwr=n;i>=0;i--)
    {
        if(a[i]=='B')rwr=i;
        rw[i]=rwr;
    }
    for(int i=k-1;i<n;i++)
        if(lb[i]<=i-k)g0[i]=f0[i-k+1];
    for(int i=n-k;i>=0;i--)
        if(rw[i]>=i+k)g1[i]=f1[i+k];
    //for(int i=0;i<=n-1;i++)printf("%d %d %d\n",i,g0[i],g1[i]);
    int S=0,T=0;
    for(int i=n-k;i>=k;i--)
    {
        if(a[i]=='X')(T*=2)%=P;
        (T+=g1[i])%=P;
        (S+=(ll)g0[i-1]*T%P)%=P;
    }
    printf("%d\n",S);
    return 0;
}