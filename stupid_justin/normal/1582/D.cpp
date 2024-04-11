#include<bits/stdc++.h>
#define int long long
#define rd(x) x=read()
using namespace std;
int read(){int x=0,f=1;char c=getchar();while (c<'0' || c>'9') {if (c=='-') f=-1;c=getchar();}while (c>='0' && c<='9') x=x*10+c-'0',c=getchar();return x*f;}
const int N=1e6+5;
int a[N],n,l,r;
int b[N];
int ans=1e18;
int cnt=0;
char s[N];
pair<int,int> p[N];
void DOIT()
{
    rd(n);for (int i=1;i<=n;i++) rd(a[i]),p[i]={a[i],i};
    sort(p+1,p+n+1);
    if (n%2==1)
    {
        for (int i=1;i<=n-3;i+=2)
        {
            if (p[i].first==p[i+1].first) a[i]=1,a[i+1]=-1;
            else a[i]=p[i+1].first,a[i+1]=-p[i].first;
        }
        a[n-2]=2*p[n].first*p[n-1].first;
        a[n-1]=-p[n].first*p[n-2].first;
        a[n]=-p[n-1].first*p[n-2].first;
    } else 
    {
        for (int i=1;i<=n;i+=2)
        {
            if (p[i].first==p[i+1].first) a[i]=1,a[i+1]=-1;
            else a[i]=p[i+1].first,a[i+1]=-p[i].first;
        }
    }
    for (int i=1;i<=n;i++) b[p[i].second]=a[i];
    for (int i=1;i<=n;i++) cout<<b[i]<<" ";cout<<"\n";
}
signed main()
{
    int JYZ;rd(JYZ);while (JYZ--) DOIT();

}
/*

*/