
#include<bits/stdc++.h>
#define int long long
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define wt(x) write(x)
#define p(x) (((x)-1)/SZ+1)
#define endl "\n"
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define ls (rt<<1)
#define rs (rt<<1|1)
#define y1 _________
using namespace std;
const int N=1e6+5;
const int M=999999;
const int K=20;
const int SZ=450;
const int mod=1e9+7;
const int inf=0x3f3f3f3f3f3f3f;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int n,m,w,cur,ans[N],S[N],flag;
int ask(int r,int d){cout<<"? "<<r<<" "<<d<<endl;int x;cin>>x;swap(cur,x);return cur-x;}
void find(){cout<<"! ";for (int i=1;i<n;i++) cout<<ans[i]<<' ';cout<<endl;exit(0);}
signed main()
{
    cin>>n>>m;w=n*m;ask(0,1);
    vector<int> S(n-1);
    for (int i=1;i<n;i++) S[i-1]=i;
    ask(0,1);
    while (1) if (ask(0,1)>0) flag=1;else if (flag) break;
    ask(0,-1);
    for (int i=0;i<w;i++)
    {
        if (ask(0,1)>0) {flag=1;continue;} else if (!flag) continue;
        if (S.empty()) continue;
        ask(0,-1);
        int l=0,r=S.size();
        bool out=0;
        while (r-l>1)
        {
            int mid=(l+r)>>1;
            if (!out) for (int j=mid;j<r;j++) ask(S[j],-1);
            else for (int j=l;j<mid;j++) ask(S[j],1);
            if (ask(0,-1)<0) r=mid,out=0;else l=mid,out=1;
            ask(0,1);
        }
        int p=S[l];
        for (int j=out-1;j<m;j++) ask(p,-1);
        ans[p]=(i-m-1+w)%w;S.erase(S.begin()+l);
        i--;ask(0,-1);flag=ask(0,1)>0;
    }
    find();
}