#include<cstdio>
#include<algorithm>
using namespace std;
#define N 2222222
#define P 51123987
typedef long long ll;
char s[N];
int n,p[N],a[N],b[N],m;
int main()
{
    scanf("%d%s",&n,s+1);
    for(int i=1,j=0;i<=n;i++)
    {
        p[i]=0;if(j+p[j]-1>=i)p[i]=min(p[2*j-i],j+p[j]-i);
        if(i+p[i]-1>=j+p[j]-1)for(j=i;i+p[i]<=n&&i-p[i]>0&&s[i-p[i]]==s[i+p[i]];p[i]++);
        a[i-p[i]+1]++,a[i+1]--,b[i+p[i]-1]++,b[i-1]--;
    }
    for(int i=1,j=0;i<=n;i++)
    {
        p[i]=0;if(j+p[j]-1>=i)p[i]=min(p[2*j-i],j+p[j]-i);
        if(i+p[i]>=j+p[j])for(j=i;i+p[i]+1<=n&&i-p[i]>0&&s[i-p[i]]==s[i+p[i]+1];p[i]++);
        a[i-p[i]+1]++,a[i+1]--,b[i+p[i]]++,b[i]--;
    }
    for(int i=1;i<=n;i++)a[i]=(a[i]+a[i-1])%P;
    for(int i=n;i>=1;i--)b[i]=(b[i]+b[i+1])%P;
    int S=0,T=0;
    for(int i=1;i<=n;i++)S=(S+(ll)a[i]*T%P)%P,T=(T+b[i])%P;
    printf("%d\n",(int)((ll)T*(T-1)/2%P-S+P)%P);
    return 0;
}