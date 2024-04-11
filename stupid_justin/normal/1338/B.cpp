#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define rd(x) x=read()
#define wt(x) write(x)
#define pii pair<int,int>
#define pq priority_queue<int>
using namespace std;
const int N=4e6+5;
const int M=170;
const int SZ=450;
const int mod=1e9+7;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if (x<0){putchar('-');x=-x;}if (x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int n,rt;
int mx,mn;
vector<int> T[N];
int dfs(int u,int fa)
{
    int t=0,ans=0;
    for (int v:T[u]) if (v!=fa) 
    {
        ans+=dfs(v,u);t++;
    }
    if (ans) mx-=ans-1;
    if (t==0) return 1;
    return 0;
    
}
int dfs2(int u,int fa)
{
    int t=0,ans=0;
    for (int v:T[u]) if (v!=fa) ans|=dfs2(v,u),t++;
    if (t==0) return 1;
    if (ans==3) mn=3;
    return (ans==1 || ans==2)?3-ans:ans;
}
signed main()
{
    rd(n);mx=n-1;mn=1;
    for (int i=1,x,y;i<n;i++) rd(x),rd(y),T[x].push_back(y),T[y].push_back(x);
    for (int i=1;i<=n;i++) if (T[i].size()>=3) rt=i;
    if (rt==0){if (n%2==1) cout<<"1 "<<(n==3?1:(n-1))<<"\n";else cout<<"3 "<<n-1<<"\n";return 0;}
    dfs(rt,0);dfs2(rt,0);
    cout<<mn<<" "<<mx<<"\n";

}
/*

*/