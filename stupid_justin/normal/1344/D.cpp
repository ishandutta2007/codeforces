#include<bits/stdc++.h>
#define int __int128
#define endl "\n"
#define rd(x) x=read()
#define wt(x) write(x)
#define pii pair<int,int>
#define pq priority_queue<int>
using namespace std;
const int N=2e5+5;
const int M=70;
const int SZ=450;
const int mod=1e9+7;
const int eps=1e-5;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if (x<0){putchar('-');x=-x;}if (x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int n,k,t;
int a[N],b[N];
long double c[N];
int p[N];
long double ans;
int f(int i,int x){return x*(a[i]-x*x);}
int dt(int i){if (b[i]==a[i]) return -1e30;return f(i,b[i]+1)-f(i,b[i]);}
bool cmp(int i,int j){return dt(i)==dt(j)?i<j:dt(i)>dt(j);}
void DOIT()
{
    rd(n);rd(k);
    long double l=-1e30,r=1e9;
    for (int i=1;i<=n;i++) rd(a[i]),c[i]=a[i],r=min(r,c[i]);
    for (int o=1;o<=500;o++)
    {
        long double mid=(l+r)/2,tot=0;
        for (int i=1;i<=n;i++) tot+=min(sqrt((a[i]-mid)/3),c[i]);
        if (tot<k) r=mid;else l=mid;
    }
    for (int i=1;i<=n;i++) b[i]=min(sqrt((a[i]-l)/3),c[i]);

    for (int i=1;i<=n;i++) t+=b[i];t=k-t;
    for (int i=1;i<=n;i++) p[i]=i;
    sort(p+1,p+n+1,cmp);
    //if (k==49985284073162){cout<<"t=";wt(t);return;}
    for (int i=1;i<=t;i++) b[p[i]]++;
    for (int i=1;i<=n;i++) wt(b[i]),cout<<" ";cout<<"\n";
}
signed main()
{
    DOIT();
}
/*
2*3*5  

*/