
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
const int N=2e6+5;
const int M=70;
const int SZ=450;
const int mod=1e9+7;
const int inf=0x3f3f3f3f3f3f3f3f;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int n,ans,res,tmp;
int a[N],v[N];
vector<int> num;
int cnt[3];

void DOIT()
{
    num.clear();
    rd(n);for (int i=1;i<=n;i++) rd(a[i]);for (int i=1;i<=n;i++) v[i]=0;
    for (int i=1;i<=n;i++){int x=i,len=0;while (!v[x]) v[x]=1,x=a[x],len++;if (len)num.push_back(len);}
    res=0;memset(cnt,0,sizeof(cnt));
    if (n%3==0)
    {
        ans=ksm(3,n/3);
        for (int x:num) res+=(x-1)/3,cnt[x%3]++;
        res+=min(cnt[1],cnt[2]);
        if (cnt[2]>cnt[1]) res+=(cnt[2]-cnt[1]);
        if (cnt[1]>cnt[2]) res+=(cnt[1]-cnt[2])/3*2;
    }
    if (n%3==1) 
    {
        ans=ksm(3,n/3-1)*4%mod;
        bool flag=0;
        for (int x:num) res+=(x-1)/3,cnt[x%3]++;
        int Res=res;
        res=inf;
        tmp=Res;
        int c[3];c[1]=cnt[1];c[2]=cnt[2];
        if (c[2]>=2) {c[2]-=2;}else {int x=2-c[2];c[2]=0;c[1]-=2*x;tmp+=x;}
        tmp+=min(c[1],c[2]);
        if (c[2]>c[1]) tmp+=(c[2]-c[1]);
        if (c[1]>c[2]) tmp+=(c[1]-c[2])/3*2;
        if (c[1]>=0 && c[2]>=0) res=min(res,tmp);
        for (int x:num) if (x>=4)
        {
            tmp=Res-(x%3!=0);
            cnt[x%3]--;cnt[(x-4)%3]++;
            tmp+=min(cnt[1],cnt[2]);
            if (cnt[2]>cnt[1]) tmp+=(cnt[2]-cnt[1]);
            if (cnt[1]>cnt[2]) tmp+=(cnt[1]-cnt[2])/3*2;
            res=min(res,tmp);
            cnt[(x-4)%3]--;cnt[x%3]++;
        }
        if (cnt[0] && cnt[1]) 
        {
            tmp=Res+1;
            cnt[1]--;
            tmp+=min(cnt[1],cnt[2]);
            if (cnt[2]>cnt[1]) tmp+=(cnt[2]-cnt[1]);
            if (cnt[1]>cnt[2]) tmp+=(cnt[1]-cnt[2])/3*2;
            res=min(res,tmp);
        }
    }
    if (n%3==2)
    {
        ans=ksm(3,n/3)*2%mod;
        for (int x:num) res+=(x-1)/3,cnt[x%3]++;
        if (cnt[2]) cnt[2]--;else cnt[1]-=2,res++;
        res+=min(cnt[1],cnt[2]);
        if (cnt[2]>cnt[1]) res+=(cnt[2]-cnt[1]);
        if (cnt[1]>cnt[2]) res+=(cnt[1]-cnt[2])/3*2;
    }
    cout<<ans<<" "<<res<<"\n";
}
signed main()
{
    int JYZ;rd(JYZ);while (JYZ--) DOIT();    
}
/*

*/