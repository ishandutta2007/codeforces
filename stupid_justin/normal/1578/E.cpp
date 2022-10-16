#include<bits/stdc++.h>
#define int long long
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
const int N=1e5+5;
const int M=70;
const int SZ=450;
const int mod=1e9+7;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int n,m,k,res;
int a[N],mx[N],id[N],t;
int OP[N],X[N],V[N];
struct opt{int op,x;double v;}mul[N];
bool cmp(opt a,opt b){return a.v>b.v;}
int now;
vector<opt>ad[N];
bool cmp2(opt a,opt b){return a.op<b.op;}
signed main()
{
    rd(n);rd(m);rd(k);
    for (int i=1;i<=n;i++) rd(a[i]);
    for (int i=1,op,u,v;i<=m;i++)
    {
        rd(op);rd(u);rd(v);
        OP[i]=op;X[i]=u;V[i]=v;
        if (op==3) mul[t++]={3,i,v*1.0};
        else if (op==2) ad[u].push_back({2,i,v*1.0});
        else if (mx[u]<v) mx[u]=v,id[u]=i;
    }
    for (int i=1;i<=n;i++)
    {
        if (mx[i]>a[i]) ad[i].push_back({1,id[i],(mx[i]-a[i])*1.0});
        sort(ad[i].begin(),ad[i].end(),cmp);
        now=a[i];for(opt j:ad[i]) mul[t]=j,mul[t++].v=(double)(now+j.v)/now,now+=j.v;
    }
    k=min(t,k);
    nth_element(mul,mul+k,mul+t,cmp);
    sort(mul,mul+k,cmp2);
    cout<<k<<"\n";
    for (int i=0;i<k;i++) cout<<mul[i].x<<" ";

}