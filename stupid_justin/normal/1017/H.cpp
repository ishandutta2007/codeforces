#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define wt(x) write(x)
#define pos(x) (((x)-1)/SZ+1)
#define endl "\n"
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define ls (rt<<1)
#define rs (rt<<1|1)
#define y1 _________
using namespace std;
const int N=2e5+5;
const int M=1e5+5;
int SZ=450;
const int mod=998244353;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int inv[N]; 
int n,m,q,ans[M],res;
int a[M],b[M],c[M],s[M];
struct query{int l,r,k,id;}Q[M];
set<int> K;
vector<query> p;
bool cmp(query x,query y){if (pos(x.l)!=pos(y.l)) return x.l<y.l;return pos(x.l)&1?x.r<y.r:x.r>y.r;}
void add(int x){res=1LL*res*(b[x]-c[x])%mod;c[x]++;}
void del(int x){c[x]--;res=1LL*res*inv[b[x]-c[x]]%mod;}
signed main()
{
    inv[1]=1;for (int i=2;i<N;i++) inv[i]=1LL*inv[mod%i]*(mod-mod/i)%mod;
    rd(n);rd(m);rd(q);
    for (int i=1;i<=n;i++) rd(a[i]);
    for (int i=1;i<=q;i++) rd(Q[i].l),rd(Q[i].r),rd(Q[i].k),Q[i].id=i,K.insert(Q[i].k);
    for (int k:K)
    {
        p.clear();for (int i=1;i<=q;i++) if (Q[i].k==k) p.push_back(Q[i]);
        memset(b,0,sizeof(b));memset(c,0,sizeof(c));for (int i=1;i<=n;i++) b[a[i]]++;for (int i=1;i<=m;i++) b[i]+=k;
        SZ=n/sqrt(p.size());SZ=max(SZ,3);
        sort(p.begin(),p.end(),cmp);
        int l=1,r=0;res=1;
        long long S=n+1LL*m*k;
        s[n]=1;for (int i=n-1;i>=0;i--) s[i]=1LL*s[i+1]*((S-i)%mod)%mod;
        for (query x:p)
        {
            while (l>x.l) add(a[--l]);
            while (l<x.l) del(a[l++]);
            while (r>x.r) del(a[r--]);
            while (r<x.r) add(a[++r]);
            int L=x.r-x.l+1;
            ans[x.id]=1LL*res*s[L]%mod;
        }
    }
    for (int i=1;i<=q;i++) cout<<ans[i]<<"\n";
}