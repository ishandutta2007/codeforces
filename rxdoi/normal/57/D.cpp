#include<cstdio>
#include<algorithm>
using namespace std;

const int Maxn=1000+9;
typedef long long LL;
int n,m,cnt;LL Ans;
int Dx[Maxn],Dy[Maxn],cx[Maxn],cy[Maxn];
char s[Maxn];

inline void calc_x()
{
    for (int i=1;i<=n;i++)
        if (Dx[i]) 
        {
            int tmp=Dx[i];
            for (int j=i+1;j<=n&&Dx[j]&&Dx[j]<Dx[j-1];j++) Ans+=2*2*(m-tmp)*(Dx[j]-1);
            for (int j=i+1;j<=n&&Dx[j]&&Dx[j]>Dx[j-1];j++) Ans+=2*2*(m-Dx[j])*(tmp-1);
            Ans+=2*2*(tmp-1)*(m-tmp);
        }
}
inline void calc_y()
{
    for (int i=1;i<=m;i++)
        if (Dy[i]) 
        {
            int tmp=Dy[i];
            for (int j=i+1;j<=m&&Dy[j]&&Dy[j]<Dy[j-1];j++) Ans+=2*2*(n-tmp)*(Dy[j]-1);
            for (int j=i+1;j<=m&&Dy[j]&&Dy[j]>Dy[j-1];j++) Ans+=2*2*(n-Dy[j])*(tmp-1);
            Ans+=2*2*(tmp-1)*(n-tmp);
        }
}

int main()
{
    scanf("%d%d",&n,&m);
    cnt=n*m;
    for (int i=1;i<=n;i++)
    {
        scanf("%s",s);
        for (int j=1;j<=m;j++) 
            if (s[j-1]=='X') Dx[i]=j,Dy[j]=i,cnt--;else cx[i]++,cy[j]++;
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++) Ans+=abs(i-j)*cx[i]*cx[j];
    for (int i=1;i<=m;i++)
        for (int j=1;j<=m;j++) Ans+=abs(i-j)*cy[i]*cy[j];
    calc_x();
    calc_y();
    printf("%.6lf\n",1.0*Ans/(1.0*cnt*cnt));
}