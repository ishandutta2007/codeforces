
#include<bits/stdc++.h>
#define rd(x) x=read()
#define wt(x) write(x)
using namespace std;
const int N=2e6+5;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int n,t;
int a[N];
vector<int> ans;
void add(int i)
{
    if (i==1 || i==n) return;
    int x=a[i-1]^a[i]^a[i+1];
    ans.push_back(i);
    a[i-1]=a[i]=a[i+1]=x;
}
void solve(int l,int r)
{
    // r-l+1 
    for (int i=l+1;i<=r;i+=2) add(i);
    for (int i=r-1;i>=l;i-=2) add(i);
}
void DOIT()
{
    t=0;rd(n);for (int i=1;i<=n;i++) rd(a[i]),t^=a[i];
    ans.clear();
    if (t!=0) {puts("NO");return;}
    if (n%2==1) solve(1,n);else 
    if (a[1]==0) solve(2,n);else 
    if (a[n]==0) solve(1,n-1);else
    {
        
        for (int i=2;i<n;i+=2) add(i);
        int p=0;
        for (int i=1;i<=n;i++) if (a[i]==0) p=i;
        if (p==0) {puts("NO");return;}
        for (int i=p+1;i<n;i+=2) add(i);
        for (int i=p-2;i>=1;i-=2) add(i);
    }
    for (int i=1;i<=n;i++) if (a[i]==1) {puts("NO");return;}
    puts("YES");
    cout<<ans.size()<<"\n";
    for (int x:ans) cout<<x-1<<" ";cout<<"\n";

}
signed main()
{
    int JYZ;rd(JYZ);while (JYZ--) DOIT();
}
/*
*/