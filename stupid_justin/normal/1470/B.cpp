#include<bits/stdc++.h>
#define int long long
#define rd(x) x=read()
using namespace std;
const int N=1e6+5;
const int M=5005;
const int mod=998244353;
const int inf=0x3f3f3f3f3f3f3f;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
int ksm(int x,int y){int ret=1;while (y){if (y&1) ret=(ret*x)%mod;x=(x*x)%mod;y>>=1;}return ret;}
int p[N],v[N],cnt;
void init()
{
    v[1]=1;
    for (int i=2;i<N;i++)
    {
        if (!v[i]) p[++cnt]=i;
        for (int j=1;j<=cnt && p[j]*i<N;j++)
        {
            v[p[j]*i]=p[j];
            if (i%p[j]==0) break;
        }
    }
}
int n,m,q,ans1,ans2,ans3;
int a[N];
map<int,int> Map;
signed main()
{
    int T;
    init();
    cin>>T;
    while(T--)
    {
        rd(n);
        Map.clear();
        ans1=ans2=ans3=0;
        for (int i=1;i<=n;i++) rd(a[i]);
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=cnt;j++)
            {
                int P=p[j]*p[j];
                if (P>a[i]) break;
                while (a[i]%P==0) a[i]/=P; 
            }
            Map[a[i]]++;
        }
        for (map<int,int>::iterator it=Map.begin();it!=Map.end();it++)
        {
            if (it->first==1) ans2+=it->second;
            else if (it->second %2==0) ans2+=it->second;
            else ans3=max(ans3,it->second);
            ans1=max(ans1,it->second);
        }
        rd(q);
        while (q--)
        {
            rd(m);if (m>0) cout<<max(ans2,ans3)<<"\n";
            else cout<<ans1<<"\n";
        }
    }
}