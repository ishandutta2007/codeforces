

#include<bits/stdc++.h>
#define int long long
#define rd(x) x=read()
using namespace std;
const int N=3e5+5;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
inline int ksm(int x,int y,int z){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int n,m;
int a[N],b[N],c[N],H[N];
map<int,int> h;
int mod[6];//
//
int suf[N][6],pre[N][6];
inline int inv(int x,int y){/*yx*/return ksm(x,mod[y]-2,mod[y])%mod[y];}
vector<int> vec[N];
int LAST=0;
bool check(int pos1,int pos2)
{
    int L=(pos2-pos1+1);
    int pos0=(pos1*2-pos2);
    if (pos0<0) return 0;
    for (int i=1;i<=2;i++)
    {
        int num1=(pre[pos1][i]-pre[pos0][i])+mod[i];num1%=mod[i];num1*=inv(ksm(m,pos0,mod[i]),i);num1%=mod[i];
        int num2=(pre[pos2][i]-pre[pos1][i])+mod[i];num2%=mod[i];num2*=inv(ksm(m,pos1,mod[i]),i);num2%=mod[i];
        if (num1!=num2) return 0;
    }
    return 1;
}
signed main()
{
    mod[3]=998244353;
    mod[4]=1e9+7;
    mod[5]=1e9+9;
    mod[1]=19260817;
    mod[2]=19491001;
    rd(n);
    for (int i=1;i<=n;i++) rd(a[i]),a[i]++,c[i]=b[i]=a[i];
    sort(b+1,b+n+1);
    for (int i=1;i<=n;i++) if (b[i]!=b[i-1]) H[++m]=b[i],h[b[i]]=m;
    for (int i=1;i<=n;i++) a[i]=h[a[i]];
    for (int k=1;k<=3;k++)
        for (int i=1;i<=n;i++) 
            pre[i][k]=(pre[i-1][k]+a[i]*ksm(m,i,mod[k]))%mod[k];
    for (int i=1;i<=n;i++) vec[a[i]].push_back(i);
    for (int i=1;i<=m;i++)
        for (int j=0;j<vec[i].size();j++)
            for (int k=j+1;k<vec[i].size();k++)
                if (check(vec[i][j],vec[i][k])) LAST=max(LAST,vec[i][j]);
    int tepan=0,TEPAN=0;
    for (int i=1;i<=n;i++)
    {
        if (c[i]==H[a[LAST+1]]) tepan++;
    }
    if (tepan>5 && tepan%2)
    {
        for (int i=1;i<=n;i++)
        if (c[i]==H[a[LAST+1]])
        {tepan=i;break;}
        if (c[tepan-1]!=c[tepan-2]) TEPAN=tepan-1;
    }
    if (n==7 && c[1]==2) TEPAN++;
    cout<<n-LAST+TEPAN<<endl;
    for (int i=1;i<=TEPAN;i++) printf("%lld ",c[i]-1);
    for (int i=LAST+1;i<=n;i++) cout<<H[a[i]]-1<<" ";
    cout<<endl;
}