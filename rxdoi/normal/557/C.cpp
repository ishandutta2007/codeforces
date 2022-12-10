#include<cstdio>
#include<cctype>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

int IN()
{
    int c,x;
    while (!isdigit(c=getchar()));x=c-'0';
    while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=1e5+19;
typedef long long LL;
struct Leg
{
    int x,d;
    bool operator < (const Leg& B) const {return x<B.x;}
} A[N];
int cnt[N],n,a;
LL Sum[N],Ans=1LL<<60;

int main()
{
    n=IN();
    For(i,1,n+1) A[i].x=IN();
    For(i,1,n+1) A[i].d=IN();
    sort(A+1,A+n+1);
    For(i,1,n+1) Sum[i]=Sum[i-1]+A[i].d;
    For(i,1,n+1)
        if (i==1||A[i].x!=A[i-1].x)
        {
            int j=i;LL tmp=0;
            while (j+1<=n&&A[j+1].x==A[j].x) j++;
            a=min(i-1,(j-i+1)-1);
            for (int k=200;k;k--)
            {
                int t=min(a,cnt[k]);
                a-=t;tmp+=t*k;
            }
            Ans=min(Ans,Sum[n]-(Sum[j]-Sum[i-1])-tmp);
            for (int k=i;k<=j;k++) cnt[A[k].d]++;
        }
    printf("%I64d\n",Ans);
}